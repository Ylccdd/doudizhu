#include <map>

#include "utils.hpp"
#include "game.hpp"
using namespace Cyan;

namespace qb {
namespace details
{

} // namespace details


void bind(Cyan::MiraiBot& bot) {
  // 用map记录哪些群启用了“反撤回”功能
    using namespace details;
    static std::map<GID_t, Data> groups;

    bot.On<GroupMessage>(
        [&](GroupMessage m) {
            string plain = m.MessageChain.GetPlainText();
            auto curr = groups[m.Sender.Group.GID];
            if (curr.enabled) {
                if(has(plain,"斗地主结束") || startsWith(plain,"/over")){
                    curr.enabled = false;
                    return;
                }
                if(has(plain,"参加游戏") || startsWith(plain,"/join")){
                    if(curr.addMember(m.Sender) == false){
                        
                    }
                    return;
                }
                if(has(plain,"游戏开始") || startsWith(plain,"/start")){
                    curr.start = true;
                    curr.gameStart();

                    return;
                }
                if(curr.start){
                    ::size_t i;
                    if((i = findStartsWith(plain,"出")) != std::string::npos){

                    }
                }
                
            } else if (has(plain,"斗地主开始") || startsWith(plain,"/doudizhu")) {
                curr.enabled = true;
                return;
            }
        }
    );
}

}  // namespace qb