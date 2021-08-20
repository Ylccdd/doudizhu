// 注意: 本项目的所有源文件都必须是 UTF-8 编码

// 这是一个“反撤回”机器人
// 在群里回复 “/anti-recall enabled.” 或者 “撤回没用” 之后
// 如果有人在群里撤回，那么机器人会把撤回的内容再发出来

#include <iostream>
#include "fwd.hpp"
using namespace std;
using namespace Cyan;

int main()
{
	MiraiBot bot;
	SessionOptions opts;
	opts.BotQQ = 836789121_qq;				// 请修改为你的机器人QQ
	opts.HttpHostname = "localhost";		// 请修改为和 mirai-api-http 配置文件一致
	opts.WebSocketHostname = "localhost";	// 同上
	opts.HttpPort = 8080;					// 同上
	opts.WebSocketPort = 8080;				// 同上
	opts.VerifyKey = "mtyddw";			// 同上
	
	while (true)
	{
		try
		{
			cout << "尝试与 mirai-api-http 建立连接..." << endl;
			bot.Connect(opts);
			break;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
		MiraiBot::SleepSeconds(1);
	}
	cout << "Bot Working..." << endl;
	qb::bind(bot);
	// 在失去与mah的连接后重连
	bot.On<LostConnection>([&](LostConnection e)
		{
			cout << e.ErrorMessage << " (" << e.Code << ")" << endl;
			while (true)
			{
				try
				{
					cout << "尝试连接 mirai-api-http..." << endl;
					bot.Reconnect();
					cout << "与 mirai-api-http 重新建立连接!" << endl;
					break;
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}
				MiraiBot::SleepSeconds(1);
			}
		});

	string cmd;
	while (cin >> cmd)
	{
		if (cmd == "exit")
		{
			// 程序结束前必须调用 Disconnect，否则 mirai-api-http 会内存泄漏。
			bot.Disconnect();
			break;
		}
	}

	return 0;
}