/**
 * main.cpp
 * @author Hirokazu Yokoyama
 * @date 2014/03/09
 */

#include <fstream>
#include <vector>
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include "person.h"

int main() {
  std::ofstream ofs("./output.xml");
  boost::archive::xml_oarchive oa(ofs);

  Person person(21, "hiro");

  PersonList plist;
  plist.list.push_back(person);
  plist.list.push_back(person);

  oa << boost::serialization::make_nvp("personlist", plist);

  ofs.close();
  return 0;
}
