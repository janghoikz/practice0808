#include <iostream>

using namespace std;

//초기화 리스트

//멤버 변수 초기화 ? 다양한 문법이 존재

//초기화 왜 해야 할까 ? 귀찮다!!!!!!
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을경우

//초기화 방법
// - 생성자 내에서 초기화 하는방법
// - 초기화 리스트 
// - c++11 문법 변수에 바로 숫자입력

//초기화 리스트
// - 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다
// - 생성자 내에서 초기화 vs 초기화 리스트
// --일반변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우에는 차이가남
// -- 정의함과 동시에 초기화가 필요한 경우 (참조 타입, const 타입)

class Inventory
{
public:
    Inventory() { cout << "invetory()" << endl; }
    Inventory(int size) { cout << "invetory()" << endl; }
    ~Inventory() { cout << "~invetory()" << endl; }
public:
    int mSize = 10;
};

class Player
{
public:
    Player() {}
    Player(int id) {}
};

// is-a(knight is-a Player? 기사는 플레이어다) ok -> 상속관계

//has-a (knight has-a invetory?) 기사는 인벤토리를 포함하고 있다 갖고있다) ok->포함관계

class Knight : public Player
{
public:
    Knight() : Player(1), mHp(100), mInventory(20),mHpRef(mHp),mHpConst(100)
        //선처리 영역
        //inventory()

    {
        mHp = 100;
    }

public:
    int mHp; //초기화 하지않으면 쓰레기값이 들어감
    Inventory mInventory;

    int& mHpRef;
    const int mHpConst;
};

int main()
{
    Knight k;

    cout << k.mHp << endl;

    //초기화 하지않으면 빌드가 성공하고 나이트 죽음
    if (k.mHp < 0)
    {
        cout << "Knight is dead" << endl;
    }
}