
#include <boost/test/unit_test.hpp>

#include "Werk/Config/MapConfig.hpp"

BOOST_AUTO_TEST_SUITE(MapConfigTest)

BOOST_AUTO_TEST_CASE(TestBasicTypes)
{
    werk::MapConfig c;

    c.values()["Pi"] = "3.25";
    c.values()["Two"] = "2";
    c.values()["Nested.Value"] = "asdf";

    BOOST_REQUIRE_EQUAL(c.getString("Pi"), "3.25");
    BOOST_REQUIRE_EQUAL(c.getDouble("Pi"), 3.25);

    BOOST_REQUIRE_EQUAL(c.getString("Two"), "2");
    BOOST_REQUIRE_EQUAL(c.getInt64("Two"), 2);
    BOOST_REQUIRE_EQUAL(c.getUint64("Two"), 2);
}

BOOST_AUTO_TEST_CASE(TestDefaultValue)
{
    werk::MapConfig c;

    BOOST_REQUIRE_EQUAL(c.getString("Pi", "3.25"), "3.25");
}

BOOST_AUTO_TEST_CASE(TestLoadFile)
{
    werk::MapConfig c;
    c.loadFromFile("src/WerkTest/Config/TestConfig.ini");

    BOOST_REQUIRE_EQUAL(c.getString("zxcv", "asdf"), "qwer");
    BOOST_REQUIRE_EQUAL(c.getInt64("abc"), 123);
}

BOOST_AUTO_TEST_SUITE_END()
