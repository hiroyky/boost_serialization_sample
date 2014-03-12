#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <list>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/list.hpp>

/**
 * Sample class for serialization
*/
class Person {
public:

    Person(int _age, const std::string& _name): age(_age), name(_name) {
    }
    int age;
    std::string name;

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
      ar & boost::serialization::make_nvp("age", age);
      ar & boost::serialization::make_nvp("name", name);
  }
};

class PersonList {
 public:
  std::list<Person> list;
private:

  friend class boost::serialization::access;
  template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
    ar & boost::serialization::make_nvp("person", *this);
  }
};

#endif
