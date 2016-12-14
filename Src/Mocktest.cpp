#define BOOST_TEST_MODULE MockTest


#include <boost/test/included/unit_test.hpp>


	class MockDef : public AngryZPR::Mock {
	public:
		void a() {
			execute("a");
		}
		void b() {
			execute("b");
		}
	};

BOOST_AUTO_TEST_CASE(MockTestCase)
{
	MockDef mockdef;
	mockdef.a();
	mockdef.b();
	mockdef.b();
	BOOST_CHECK_EQUAL(mockdef.getExecuteNum('a'), 1);
	BOOST_CHECK_EQUAL(mockdef.getExecuteNum('b'), 2);
	mockdef.reset();
	BOOST_CHECK_EQUAL(mockdef.getExecuteNum('a'), 0);
	BOOST_CHECK_EQUAL(mockdef.getExecuteNum('b'), 0);

	// To simplify this example test, let's suppose we'll test 'float'.
	// Some test are stupid, but all should pass.
	float x = 9.5f;

	BOOST_CHECK(x != 0.0f);
	BOOST_CHECK_EQUAL((int)x, 8);
	BOOST_CHECK_CLOSE(x, 9.5f, 0.0001f); // Checks differ no more then 0.0001%

}
