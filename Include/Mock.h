#ifndef __MOCK_H__
#define __MOCK_H__
#include <map>
#include <string>

namespace AngryZPR {
/*
 * Rodzic dla wszystkich obiektów które sa mocjowane dla testów jednostkowych
 */
	class Mock {
	private:
		std::map<std::string, int> mExecuteNum;
	protected:
		void execute(std::string methodName);

	public:
		int getExecuteNum(std::string method);
		void reset();
	};
}
#endif
