
#include "native/CCAlertViewDelegate.h"

#if CC_LUA_ENGINE_ENABLED > 0
#include "CCLuaEngine.h"
#endif

#include <string>

using namespace std;

USING_NS_CC;
USING_NS_CC_EXTRA;

class CCNative_win32
{
//    UIActivityIndicatorView *activityIndicatorView_;
    //NSAlert *alertView_;
public:
	static CCNative_win32* sharedInstance(void);

	void showActivityIndicator(void);
	void hideActivityIndicator(void);

	void createAlertView(const char* title, const char *message, const char* cancelButtonTitle);
	int addAlertButton(const char* buttonTitle);
	void showAlertViewWithDelegate(CCAlertViewDelegate *delegate);
	void removeAlertView(void);
	void cancelAlertView(void);

#if CC_LUA_ENGINE_ENABLED > 0
	void showAlertViewWithLuaListener(LUA_FUNCTION listener);
	void removeAlertViewLuaListener(void);
#endif

	const string getInputText(const char* title, const char* message, const char* defaultValue);

private:
	static CCNative_win32* s_sharedInstance;

	CCNative_win32(void);

	string m_alertViewTitle;
	string m_alertViewMessage;
};
