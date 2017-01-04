#define BOOST_TEST_MODULE MockTest


#include <boost/test/included/unit_test.hpp>

#include "../Include/Mock.h"
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
	BOOST_CHECK_EQUAL(mockdef.getExecuteNum("a"), 1);
	BOOST_CHECK_EQUAL(mockdef.getExecuteNum("b"), 2);
	mockdef.reset();
	BOOST_CHECK_EQUAL(mockdef.getExecuteNum("a"), 0);
	BOOST_CHECK_EQUAL(mockdef.getExecuteNum("b"), 0);



}
