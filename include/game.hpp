#ifndef _GAME_HPP_
#define _GAME_HPP_
#include "fwd.hpp"
namespace qb{
using namespace Cyan;

struct Card{
    int point;

    operator std::string() const {
        if(point <= 10) return std::to_string(point);
        if(point == 11) return "J";
        if(point == 12) return "Q";
        if(point == 13) return "K";
        if(point == 14) return "鬼";
        if(point == 15) return "王";
        assert(false);
    }
    // 避免传指针
    friend bool operator<(Card lhs, Card rhs) {
        return lhs.point < rhs.point;
    }
};
struct Member{
    std::string name;
    QQ_t qid;
    vector<Card> cards; // 地主20张
private:
    friend class Data;
    void sort (){

    }
};
struct Data {
    bool enabled = false;
    bool start   = false;
    
    void gameStart(){
        std::string s;
        s.append("鬼王");

    }

    // 满时返回false
    bool addMember(const GroupMember& member){
        assert(!start && enabled);
        if(curr_ == 3) return false;
        people_[curr_].name = member.MemberName;
        people_[curr_].qid = member.QQ;
        ++curr_;
        return true;
    }
private:
    Member people_[3]; 
    int curr_{};
    Member& getCurrentPeople() { return people_[curr_]; }
    void next(){
        ++curr_;
        if(curr_ == 3){
            curr_ = 0;
        }
    }
};


}







#endif