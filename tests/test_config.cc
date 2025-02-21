#include "qsgy/config.h"
#include "qsgy/log.h"
#include <yaml-cpp/yaml.h>

qsgy::ConfigVar<int>::ptr g_int_value_config = 
	qsgy::Config::Lookup("system.port", (int)8080, "system port");

//qsgy::ConfigVar<float>::ptr g_int_float_value_config = 
//	qsgy::Config::Lookup("system.port", (float)8080, "system port");

qsgy::ConfigVar<float>::ptr g_float_value_config = 
	qsgy::Config::Lookup("system.value", (float)10.2f, "system value");

qsgy::ConfigVar<std::vector<int> >::ptr g_int_vec_value_config = 
	qsgy::Config::Lookup("system.int_vec", std::vector<int>{1, 2}, "system int vec");

qsgy::ConfigVar<std::list<int> >::ptr g_int_list_value_config = 
	qsgy::Config::Lookup("system.int_list", std::list<int>{1, 2}, "system int list");

qsgy::ConfigVar<std::set<int> >::ptr g_int_set_value_config = 
	qsgy::Config::Lookup("system.int_set", std::set<int>{1, 2}, "system int set");

qsgy::ConfigVar<std::unordered_set<int> >::ptr g_int_unset_value_config = 
	qsgy::Config::Lookup("system.int_unset", std::unordered_set<int>{1, 2}, "system int unset");

qsgy::ConfigVar<std::map<std::string, int> >::ptr g_str_int_map_value_config = 
	qsgy::Config::Lookup("system.str_int_map", std::map<std::string, int>{{"k", 2}}, "system str int map");

qsgy::ConfigVar<std::unordered_map<std::string, int> >::ptr g_str_int_unmap_value_config = 
	qsgy::Config::Lookup("system.str_int_unmap", std::unordered_map<std::string, int>{{"k", 2}}, "system str int unmap");

void print_yaml(const YAML::Node& node, int level) {
	if(node.IsScalar()) {
		QSGY_LOG_INFO(QSGY_LOG_ROOT()) << std::string(level * 4, ' ') 
			<< node.Scalar() << " - " << node.Type() << " - " << level;
	} else if( node.IsNull()) {		
		QSGY_LOG_INFO(QSGY_LOG_ROOT()) << std::string(level * 4, ' ') 
			<< "NULL - " << node.Type() << " - " << level;
	} else if( node.IsMap()) {
		for(auto it = node.begin();
				it != node.end(); ++it) {		
		QSGY_LOG_INFO(QSGY_LOG_ROOT()) << std::string(level * 4, ' ') 
			<< it->first << " - " << it->second.Type() << " - " << level;
		print_yaml(it->second, level + 1);
		}
	} else if(node.IsSequence()) {
		for(size_t i = 0; i < node.size(); ++i) {	
		QSGY_LOG_INFO(QSGY_LOG_ROOT()) << std::string(level * 4, ' ') 
			<< i << " - " << node[i].Type() << " - " << level;
		print_yaml(node[i], level + 1);
		}
	}
}

void test_yaml(){
	YAML::Node root = YAML::LoadFile("/home/qsgy/workspace/qsgy/bin/conf/test.yml");
	print_yaml(root, 0);

	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << root;
}

void test_config(){
	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << "before: " << g_int_value_config->getValue();
	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << "before: " << g_float_value_config->toString();

#define XX(g_var, name, prefix) \
	{ \
		auto& v = g_var->getValue(); \
		for(auto& i : v) { \
			QSGY_LOG_INFO(QSGY_LOG_ROOT()) << #prefix " " #name ": " << i; \
		} \
		QSGY_LOG_INFO(QSGY_LOG_ROOT()) << #prefix " " #name " yaml: " << g_var->toString(); \
	} 

#define XX_M(g_var, name, prefix) \
	{ \
		auto& v = g_var->getValue(); \
		for(auto& i : v) { \
			QSGY_LOG_INFO(QSGY_LOG_ROOT()) << #prefix " " #name ": {"\
				<< i.first << " - " << i.second << "}"; \
		} \
		QSGY_LOG_INFO(QSGY_LOG_ROOT()) << #prefix " " #name " yaml: " << g_var->toString(); \
	}

	XX(g_int_vec_value_config, int_vec, before);
	XX(g_int_list_value_config, int_list, before);
	XX(g_int_set_value_config, int_set, before);
	XX(g_int_unset_value_config, int_unset, before);
	XX_M(g_str_int_map_value_config, str_int_map, before);
	XX_M(g_str_int_unmap_value_config, str_int_unmap, before);

	YAML::Node root = YAML::LoadFile("/home/qsgy/workspace/qsgy/bin/conf/test.yml");
	qsgy::Config::LoadFromYaml(root);

	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << "after: " << g_int_value_config->getValue();
	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << "after: " << g_float_value_config->toString();

	XX(g_int_vec_value_config, int_vec, after);
	XX(g_int_list_value_config, int_list, after);	
	XX(g_int_set_value_config, int_set, after);	
	XX(g_int_unset_value_config, int_unset, after);	
	XX_M(g_str_int_map_value_config, str_int_map, after);	
	XX_M(g_str_int_unmap_value_config, str_int_unmap, after);	
}

class Person {
	public:
		std::string m_name = "";
	int m_age = 0;
	bool m_sex = 0;

	std::string toString() const {
		std::stringstream ss;
		ss << "[Person name=" << m_name
			<<" age=" << m_age
			<<" sex=" << m_sex
			<<"]";
		return ss.str();
	}

	bool operator== (const Person& p) const {
		return p.m_name == m_name && p.m_age == m_age && p.m_sex == m_sex;
	}
};

namespace qsgy {
//模板偏特化
template<>
class LexicalCast<std::string, Person> {
public:
	Person operator() (const std::string& v) {
		YAML::Node node = YAML::Load(v);
		Person p;
		p.m_name = node["name"].as<std::string>();
		p.m_age = node["age"].as<int>();
		p.m_sex = node["sex"].as<bool>();
		return p;
	}
};

template<>
class LexicalCast<Person, std::string> {
public:
	std::string operator() (const Person& p) {
		YAML::Node node;
		node["name"] = p.m_name;
		node["age"] = p.m_age;
		node["sex"] = p.m_sex;
		std::stringstream ss;
		ss << node;
		return ss.str();
	}
};


}

qsgy::ConfigVar<Person>::ptr g_person = 
	qsgy::Config::Lookup("class.person", Person(), "system person");

qsgy::ConfigVar<std::map<std::string, Person> >::ptr g_person_map = 
	qsgy::Config::Lookup("class.map", std::map<std::string, Person>(), "system person map");

qsgy::ConfigVar<std::map<std::string, std::vector<Person> > >::ptr g_person_vec_map = 
	qsgy::Config::Lookup("class.vec_map", std::map<std::string, std::vector<Person> >(), "system person vec map");

void test_class(){
	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << "before: " << g_person->getValue().toString() << " - " << g_person->toString();

#define XX_PM(g_var, prefix) \
	{ \
		auto m = g_var->getValue(); \
		for(auto i : m) { \
			QSGY_LOG_INFO(QSGY_LOG_ROOT()) << prefix << ": " << i.first << " - " << i.second.toString(); \
		} \
		QSGY_LOG_INFO(QSGY_LOG_ROOT()) << prefix << ": size= " << m.size(); \
	} \

	XX_PM(g_person_map, "class.map before");
	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << g_person_vec_map->toString();

	g_person->addListener(10, [](const Person old_value, const Person new_value){
		QSGY_LOG_INFO(QSGY_LOG_ROOT()) << "old_value: " << old_value.toString() << " after: " << new_value.toString();
	});

	YAML::Node root = YAML::LoadFile("/home/qsgy/workspace/qsgy/bin/conf/test.yml");
	qsgy::Config::LoadFromYaml(root);

	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << "after: " << g_person->getValue().toString() << " - " <<g_person->toString();

	XX_PM(g_person_map, "class.map after");
	QSGY_LOG_INFO(QSGY_LOG_ROOT()) << g_person_vec_map->toString();
}

int main(int arg, char** args) {
//	test_config();	
//	test_yaml();
	test_class();
	return 0;
}
