#include "../Include/Mock.h"

namespace AngryZPR {
	void Mock::execute(std::string methodName) {
		if(mExecuteNum.count(methodName) == 0)
		{
			mExecuteNum.insert(std::pair<std::string, int>(methodName, 0));
		}
		mExecuteNum[methodName] = mExecuteNum[methodName] + 1; 
	}
	int Mock::getExecuteNum(std::string method) {
		if(mExecuteNum.count(method) == 0)
			return 0;
		else
			return mExecuteNum[method];
	}
	void Mock::reset() {
		mExecuteNum.clear();
	}
}