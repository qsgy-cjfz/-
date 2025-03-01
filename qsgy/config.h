#ifndef __QSGY_CONFIG_H__
#define __QSGY_CONFIG_H__

#include <memory>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <yaml-cpp/yaml.h>
#include "qsgy/log.h"
#include <vector>
#include <map>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>

namespace qsgy {

class ConfigVarBase {
public:
	typedef std::shared_ptr<ConfigVarBase> ptr;
	ConfigVarBase(const std::string& name, const std::string& description = "")
		:m_name(name)
		,m_description(description) {
		std::transform(m_name.begin(), m_name.end(), m_name.begin(), ::tolower);
	}
	virtual ~ConfigVarBase() {}

	const std::string& getName() const { return m_name;}
	const std::string& getDescription() const { return m_description;}

	virtual std::string toString() = 0;
	virtual bool fromString(const std::string& val) = 0;
	virtual std::string getTypeName() const = 0;
protected:
		std::string m_name;
		std::string m_description;
};

//F from_type, T to_type
template<class F, class T>
class LexicalCast {
public:
	T operator()(const F& v) {
		return boost::lexical_cast<T>(v);
	}
};

template<class T>
class LexicalCast<std::string, std::vector<T> > {
public:
	std::vector<T> operator() (const std::string& v) {
		YAML::Node node = YAML::Load(v);
		typename std::vector<T> vec;
		std::stringstream ss;
		for(size_t i = 0; i < node.size(); ++i) {
			ss.str("");
			ss << node[i];
			vec.push_back(LexicalCast<std::string, T>() (ss.str()));
		}
		return vec;
	}
};

template<class T>
class LexicalCast<std::vector<T>, std::string> {
public:
	std::string operator() (const std::vector<T>& v) {
		YAML::Node node;
		for(auto& i : v) {
			node.push_back(YAML::Load(LexicalCast<T, std::string>() (i)));
		}
		std::stringstream ss;
		ss << node;
		return ss.str();
	}
};

template<class T>
class LexicalCast<std::string, std::list<T> > {
public:
	std::list<T> operator() (const std::string& v) {
		YAML::Node node = YAML::Load(v);
		typename std::list<T> vec;
		std::stringstream ss;
		for(size_t i = 0; i < node.size(); ++i) {
			ss.str("");
			ss << node[i];
			vec.push_back(LexicalCast<std::string, T>() (ss.str()));
		}
		return vec;
	}
};

template<class T>
class LexicalCast<std::list<T>, std::string> {
public:
	std::string operator() (const std::list<T>& v) {
		YAML::Node node;
		for(auto& i : v) {
			node.push_back(YAML::Load(LexicalCast<T, std::string>() (i)));
		}
		std::stringstream ss;
		ss << node;
		return ss.str();
	}
};

template<class T>
class LexicalCast<std::string, std::set<T> > {
public:
	std::set<T> operator() (const std::string& v) {
		YAML::Node node = YAML::Load(v);
		typename std::set<T> vec;
		std::stringstream ss;
		for(size_t i = 0; i < node.size(); ++i) {
			ss.str("");
			ss << node[i];
			vec.insert(LexicalCast<std::string, T>() (ss.str()));
		}
		return vec;
	}
};

template<class T>
class LexicalCast<std::set<T>, std::string> {
public:
	std::string operator() (const std::set<T>& v) {
		YAML::Node node;
		for(auto& i : v) {
			node.push_back(YAML::Load(LexicalCast<T, std::string>() (i)));
		}
		std::stringstream ss;
		ss << node;
		return ss.str();
	}
};

template<class T>
class LexicalCast<std::string, std::unordered_set<T> > {
public:
	std::unordered_set<T> operator() (const std::string& v) {
		YAML::Node node = YAML::Load(v);
		typename std::unordered_set<T> vec;
		std::stringstream ss;
		for(size_t i = 0; i < node.size(); ++i) {
			ss.str("");
			ss << node[i];
			vec.insert(LexicalCast<std::string, T>() (ss.str()));
		}
		return vec;
	}
};

template<class T>
class LexicalCast<std::unordered_set<T>, std::string> {
public:
	std::string operator() (const std::unordered_set<T>& v) {
		YAML::Node node;
		for(auto& i : v) {
			node.push_back(YAML::Load(LexicalCast<T, std::string>() (i)));
		}
		std::stringstream ss;
		ss << node;
		return ss.str();
	}
};

template<class T>
class LexicalCast<std::string, std::map<std::string, T> > {
public:
	std::map<std::string, T> operator() (const std::string& v) {
		YAML::Node node = YAML::Load(v);
		typename std::map<std::string, T> vec;
		std::stringstream ss;
		for(auto it = node.begin();
				it != node.end(); ++it) {
			ss.str("");
			ss << it->second;
			vec.insert(std::make_pair(it->first.Scalar(),
						LexicalCast<std::string, T>() (ss.str())));
		}
		return vec;
	}
};

template<class T>
class LexicalCast<std::map<std::string, T>, std::string> {
public:
	std::string operator() (const std::map<std::string, T>& v) {
		YAML::Node node;
		for(auto& i : v) {
			node[i.first] = YAML::Load(LexicalCast<T, std::string>() (i.second));
		}
		std::stringstream ss;
		ss << node;
		return ss.str();
	}
};

template<class T>
class LexicalCast<std::string, std::unordered_map<std::string, T> > {
public:
	std::unordered_map<std::string, T> operator() (const std::string& v) {
		YAML::Node node = YAML::Load(v);
		typename std::unordered_map<std::string, T> vec;
		std::stringstream ss;
		for(auto it = node.begin();
				it != node.end(); ++it) {
			ss.str("");
			ss << it->second;
			vec.insert(std::make_pair(it->first.Scalar(),
						LexicalCast<std::string, T>() (ss.str())));
		}
		return vec;
	}
};

template<class T>
class LexicalCast<std::unordered_map<std::string, T>, std::string> {
public:
	std::string operator() (const std::unordered_map<std::string, T>& v) {
		YAML::Node node;
		for(auto& i : v) {
			node[i.first] = YAML::Load(LexicalCast<T, std::string>() (i.second));
		}
		std::stringstream ss;
		ss << node;
		return ss.str();
	}
};


//FromStr T operator() (const std::string&)
//ToStr std::string operator() (const T&)
template<class T, class FromStr = LexicalCast<std::string, T>
				, class ToStr = LexicalCast<T, std::string> >
class ConfigVar : public ConfigVarBase {
public:
	typedef std::shared_ptr<ConfigVar> ptr;
	typedef std::function<void(const T& old_value, const T& new_value)> on_change_cb;	/*这个typedef语句定义了一个名为on_change_cb的类型别名，它表示一个接受两个const T&类型参数并返回void的函数类型。这种类型别名通常用于定义回调函数，使得代码更加简洁和易读。*/

	ConfigVar(const std::string& name
			,const T& default_value
			,const std::string& description = "")
		:ConfigVarBase(name, description)
		,m_val(default_value) {
	}

	std::string toString() override {
		try {
			//return boost::lexical_cast<std::string>(m_val);
			return ToStr()(m_val);
		} catch (std::exception& e) {
			QSGY_LOG_ERROR(QSGY_LOG_ROOT()) << "ConfigVar::soString exception"
				<< e.what() << " convert: " << typeid(m_val).name() << "to string";
		}
		return "";
	}
	bool fromString(const std::string& val) override{
		try {
			//m_val = boost::lexical_cast<T>(val);
			setValue(FromStr()(val));
		} catch (std::exception& e) {
			QSGY_LOG_ERROR(QSGY_LOG_ROOT()) << "ConfigVar::soString exception"
				<< e.what() << " convert: string to" << typeid(m_val).name()
				<< " - " << val;	
		}
		return false;
	}
	const T getValue() const {return m_val;}
	
	void setValue(const T& val) {
		if(m_val == val) {
			return;
		}
		for(auto i : m_cbs) {
			i.second(m_val, val);
		}
		m_val = val;
	}
	
	std::string getTypeName() const override { return typeid(T).name();}

	void addListener(uint64_t key, on_change_cb cb) {
		m_cbs[key] = cb;
	}

	void delListener(uint64_t key) {
		m_cbs.erase(key);
	}

	on_change_cb getListener(uint64_t key) {
		auto it = m_cbs.find(key);
		return it == m_cbs.end() ? nullptr : it->second;
	}

	void clearListener() {
		m_cbs.clear();
	}
private:
	T m_val;
	//变更回调函数组,uint64_t key,要求唯一，一般可以用hash
	std::map<uint64_t, on_change_cb> m_cbs;
};

class Config {
public:
	typedef std::map<std::string, ConfigVarBase::ptr> ConfigVarMap;

	template<class T>
	static typename ConfigVar<T>::ptr Lookup(const std::string& name, 
			const T& default_value, const std::string& description = ""){
		auto it = GetDatas().find(name);
		if(it !=GetDatas().end()) {
			auto tmp = std::dynamic_pointer_cast<ConfigVar<T> >(it->second);	//将找到的配置变量转换为 ConfigVar<T> 类型的智能指针。
			if(tmp) {
				QSGY_LOG_INFO(QSGY_LOG_ROOT()) << "Lookup name= " << name << " exits";
				return tmp;
			} else {
				QSGY_LOG_ERROR(QSGY_LOG_ROOT()) << "Lookup name = " << name << " exits but type not "
					<< typeid(T).name() << " real_type =" << it->second->getTypeName() << " " << it->second->toString();
				return nullptr;
			}
		}
		
		if(name.find_first_not_of("abcdefghijklmnopqrstuvwxyz._0123456789") 
				!= std::string::npos) {
			QSGY_LOG_ERROR(QSGY_LOG_ROOT()) << "Lookup name invalid " << name;
			throw std::invalid_argument(name);
		}
		typename ConfigVar<T>::ptr v(new ConfigVar<T>(name, default_value, description));
		GetDatas()[name] = v;
		return v;
	}

	template<class T>
		static typename ConfigVar<T>::ptr Lookup(const std::string& name) {
			auto it = GetDatas().find(name);
			if(it == GetDatas().end()) {
				return nullptr;
			}
			return std::dynamic_pointer_cast<ConfigVar<T> >(it->second); 
		}
	static void LoadFromYaml(const YAML::Node& root);
	static ConfigVarBase::ptr LookupBase(const std::string& name);
private:
	static ConfigVarMap& GetDatas() {
		static ConfigVarMap s_datas;
		return s_datas;
	}
};

}

#endif
