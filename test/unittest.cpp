//#define BOOST_TEST_MAIN
//#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "flytoelephant.h"

BOOST_AUTO_TEST_SUITE(TestFlytToElephant)

BOOST_AUTO_TEST_CASE(FromExample)
{
    std::vector<std::string> dictWorld;
    dictWorld.push_back("КОТ");
    dictWorld.push_back("ТОН");
    dictWorld.push_back("НОТА");
    dictWorld.push_back("КОТЫ");
    dictWorld.push_back("РОТ");
    dictWorld.push_back("РОТА");
    dictWorld.push_back("ТОТ");

    FlyToElephant* el = new FlyToElephant("КОТ", "ТОН", dictWorld);

    std::vector<std::string> result;

    BOOST_CHECK_NO_THROW(result =  el->Execute());

    BOOST_REQUIRE(result.size() == 3);

    delete el;
    el = nullptr;
}
BOOST_AUTO_TEST_SUITE_END()
