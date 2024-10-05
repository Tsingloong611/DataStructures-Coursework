#include"LinkList.h"
namespace Common {
	bool CheckSkip(bool& enable_skip, int mode) {
		char skip_choose = '\0';
		if (mode == 0) {
			DList::CheckInput(skip_choose, "Do you want to cancel this operation? (y for yes, others for no): ");
		}
		if (enable_skip && skip_choose == 'y') {
			enable_skip = false;
			return true;
		}
		enable_skip = false;
		return false;
	}
}