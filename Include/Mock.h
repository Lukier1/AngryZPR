#ifndef __MOCK_H__
#define __MOCK_H__
namespace AngryZPR {
	#include <map>
	class Mock {
	private:
		Map<std::string, int> mExecuteNum;
	protected:
		void execute(std::string methodName);

	public:
		int getExecuteNum(std::string method);
		void reset();
	};
}
#endif