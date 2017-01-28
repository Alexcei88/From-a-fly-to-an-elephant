//#define BOOST_TEST_MAIN
//#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <vector>
#include <string>
#include <exception>

#include "flytoelephant.h"

BOOST_AUTO_TEST_SUITE(TestFlyToElephant)

BOOST_AUTO_TEST_CASE(FromExampleTestWork)
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

    BOOST_REQUIRE(result[0] == "КОТ");
    BOOST_REQUIRE(result[1] == "ТОТ");
    BOOST_REQUIRE(result[2] == "ТОН");

    delete el;
    el = nullptr;
}

BOOST_AUTO_TEST_CASE(NOTFoundElephant)
{
    std::vector<std::string> dictWorld;
    dictWorld.push_back("КОТ");
    dictWorld.push_back("ТОН");
    dictWorld.push_back("НОТА");
    dictWorld.push_back("КОТЫ");
    dictWorld.push_back("РОТ");
    dictWorld.push_back("РОТА");
    dictWorld.push_back("ТОK");

    FlyToElephant* el = new FlyToElephant("КОТ", "ТОН", dictWorld);
    BOOST_CHECK_THROW(el->Execute(), std::exception);

    delete el;
    el = nullptr;
}


BOOST_AUTO_TEST_CASE(MoreBigFlyToElephant)
{
    std::vector<std::string> dictWorld;
    dictWorld.push_back("РОКОТ");
    dictWorld.push_back("НАЛОГ");
    dictWorld.push_back("ТОПОР");
    dictWorld.push_back("РОБОТ");
    dictWorld.push_back("ХОБОТ");
    dictWorld.push_back("КХОБОТА");
    dictWorld.push_back("ГОМОН");
    dictWorld.push_back("ТОБОЛ");
    dictWorld.push_back("МОЛОТ");
    dictWorld.push_back("ХОЛОТ");
    dictWorld.push_back("МОЛОТОК");
    dictWorld.push_back("КОМОД");
    dictWorld.push_back("МОЛОХ");
    dictWorld.push_back("МОТОК");
    dictWorld.push_back("ХОЛОД");
    dictWorld.push_back("ГОЛОД");
    dictWorld.push_back("МОЛОД");
    dictWorld.push_back("МОЛОП");
    dictWorld.push_back("CГОЛОД");
    dictWorld.push_back("ГОРОД");
    dictWorld.push_back("НАЛОП");
    dictWorld.push_back("ДОРОС");
    dictWorld.push_back("РОСОЛ");
    dictWorld.push_back("ПОСОЛ");
    dictWorld.push_back("CГОЛОДА");
    dictWorld.push_back("ТОСОЛ");
    dictWorld.push_back("СОЛОП");
    dictWorld.push_back("ХОЛОП");
    dictWorld.push_back("ПОЛОГ");
    dictWorld.push_back("МАЛОП");
    dictWorld.push_back("ТОПОР");
    dictWorld.push_back("РОБОТ");
    dictWorld.push_back("ХОБОТ");
    dictWorld.push_back("КХОБОТА");
    dictWorld.push_back("ГОМОН");
    dictWorld.push_back("ТОБОЛ");
    dictWorld.push_back("МОЛОТ");
    dictWorld.push_back("ХОЛОТ");
    dictWorld.push_back("МОЛОТОК");
    dictWorld.push_back("КОМОД");
    dictWorld.push_back("МОЛОХ");
    dictWorld.push_back("МОТОК");
    dictWorld.push_back("ХОЛОД");
    dictWorld.push_back("ГОЛОД");
    dictWorld.push_back("МОЛОД");
    dictWorld.push_back("МОЛОП");
    dictWorld.push_back("CГОЛОД");
    dictWorld.push_back("ГОРОД");
    dictWorld.push_back("НАЛОП");
    dictWorld.push_back("ДОРОС");
    dictWorld.push_back("РОСОЛ");
    dictWorld.push_back("ПОСОЛ");
    dictWorld.push_back("CГОЛОДА");
    dictWorld.push_back("ТОСОЛ");
    dictWorld.push_back("СОЛОП");
    dictWorld.push_back("ХОЛОП");
    dictWorld.push_back("ПОЛОГ");
    dictWorld.push_back("МАЛОП");
    dictWorld.push_back("РОТ");
    dictWorld.push_back("РОТА");
    dictWorld.push_back("ТОK");

    FlyToElephant* el = new FlyToElephant("РОКОТ", "НАЛОГ", dictWorld);
    std::vector<std::string> result;

    BOOST_CHECK_NO_THROW(result = el->Execute());

    BOOST_REQUIRE(result.size() == 9);

    BOOST_REQUIRE(result[0] == "РОКОТ");
    BOOST_REQUIRE(result[1] == "РОБОТ");
    BOOST_REQUIRE(result[2] == "ХОБОТ");
    BOOST_REQUIRE(result[3] == "ХОЛОТ");
    BOOST_REQUIRE(result[4] == "МОЛОТ");
    BOOST_REQUIRE(result[5] == "МОЛОП");
    BOOST_REQUIRE(result[6] == "МАЛОП");
    BOOST_REQUIRE(result[7] == "НАЛОП");
    BOOST_REQUIRE(result[8] == "НАЛОГ");

    delete el;
    el = nullptr;
}

BOOST_AUTO_TEST_SUITE_END()
