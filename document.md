# 設計組函式庫文件

## 工具 utils.h

```cpp
typedef std::pair<int, int> intPair;
```

```cpp
namespace  constants{
    constexpr int BASERADIUS = 5000;
    constexpr int WINDRADIUS = 1280;
    constexpr int CTRLRADIUS = 2200;
    constexpr int SHLDRADIUS = 2200;
    constexpr int IDAIRADIUS = 300;
    constexpr int SPELLCOSTS = 10;
}
```

常用數值

```cpp
int distance(intPair, intPair);
```

計算兩組座標間之距離

```cpp
intPair& operator +=(intPair &lhs, const intPair &rhs);
const intPair operator +(const intPair &lhs, const intPair &rhs);
intPair& operator -=(intPair &lhs, const intPair &rhs);
const intPair operator -(const intPair &lhs, const intPair &rhs);
intPair& operator *=(intPair &lhs, const int scalar);
const intPair operator *(const intPair &lhs, const int scalar);
intPair& operator /=(intPair &lhs, const int divider);
const intPair operator /(const intPair &lhs, const int divider);
intPair& operator %=(intPair &lhs, const int modulo);
const intPair operator %(const intPair &lhs, const int modulo);
```

提供座標(std::pair<int, int>)之間的四則運算之運算子多載

# 類別定義

## 架構

![Untitled](https://file.notion.so/f/s/d2524a99-0fc8-4233-8093-d3aae63caa7f/Untitled.png?id=d1d118d3-9563-4bb7-ae42-b7656bf88d7d&table=block&spaceId=d6fb5fcf-fd22-4956-bf71-4828d973340c&expirationTimestamp=1681543144832&signature=4urXKcQhqwoAg4_eQeBN57bOxSj73pcC4Egz_yOsgTg&downloadName=Untitled.png)

## class Entity

```cpp
intPair getCoord() const;
```

回傳該實體之座標

### 回傳值

- intPair(x, y)

```cpp
int distToCoord(intPair coord) const;
```

計算與該座標之距離

### 傳入值

- intPair(x, y)

### 回傳值

- int 距離

```cpp
bool getIsControlled() const;
```

取得 isControlled 參數

### 回傳值

- bool isControlled

```cpp
int getShieldLife() const;
```

取得 shieldLife 參數

### 回傳值

- int shieldLife

```cpp
Entity(){};
Entity(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor, intPair baseCoord);
```

建構子

### 傳入值

- int 11 項基本參數
- intPiar 我方基地座標

## class Monster : public Entity

```cpp
Monster() {};
Monster(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor,intPair baseCoord);
```

建構子

### 傳入值

- int 11 項基本參數
- intPiar 我方基地座標

## class Ally : public Entity

```cpp
bool goCoord(intPair coord);
```

加入前往該座標之指令，如已有指令則失敗

### 傳入值

- intPair(x, y)

### 回傳值

- bool 成功 ( true ) 失敗 ( false )

```cpp
bool goDefaultCoord(Player &player);
```

加入前往預設座標之指令，如已有指令則失敗

### 傳入值

- Player& 玩家本身

### 回傳值

- bool 成功 ( true ) 失敗 ( false )

```cpp
bool goEntity(int id, Player &player);
```

加入前往該實體座標之指令，如已有指令則失敗

### 傳入值

- int 實體之 ID
- Player& 玩家本身

### 回傳值

- bool 成功 ( true ) 失敗 ( false )

```cpp
bool spellWind(intPair coord);
bool spellWind(int x, int y);
```

加入施放推向該座標之風魔法指令，如已有指令或魔力不足則失敗

### 傳入值

- int x, y 座標 or intPair(x,y)座標

### 回傳值

- bool 成功 ( true ) 失敗 ( false )

```cpp
bool control(int id, int x, int y, Player &player);
```

加入施放控制該實體前往指定座標之指令，如已有指令、已被控制、距離不足或魔力不足則失敗

### 傳入值

- int 實體之 ID
- int x, y 座標
- Player& 玩家本身

### 回傳值

- bool 成功 ( true ) 失敗 ( false )

```cpp
bool shield(int id, Player &player);
```

加入施放護盾給指定實體之指令，如已有指令、已有護盾、距離不足或魔力不足則失敗

### 傳入值

- int 實體之 ID
- Player& 玩家本身

### 回傳值

- bool 成功 ( true ) 失敗 ( false )

```cpp
std::string getCommand() const;
```

取得指令

### 回傳值

- std::string 指令

```cpp
std::ostream& operator << (std::ostream & os,const Ally & a);
```

輸出指令之運算子多載

### 運算元

- std::ostream 左運算元
- Ally& 右運算元欲輸出指令之 Ally

```cpp
Ally(){};
Ally(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor, intPair baseCoord);
```

建構子

### 傳入值

- int 11 項基本參數
- intPiar 我方基地座標

## class Enemy : public Entity

```cpp
Enemy(){};
Enemy(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor, intPair baseCoord);
```

建構子

### 傳入值

- int 11 項基本參數
- intPiar 我方基地座標

## class Player

```cpp
static int health, enemyHealth;
static int mana, enemyMana;
```

雙方體力和魔力

```cpp
const int allyBaseX, allyBaseY, enemyBaseX, enemyBaseY, heroesNum;
```

雙方基地座標即可用英雄

```cpp
std::map<int, Monster> monsters;
std::map<int, Ally> allies;
std::map<int, Enemy> enemies;
```

儲存所有場上ID 和實體之映射

```cpp
std::vector<intPair> allyDefaultCoord;
```

可更改之預設 Ally 位置

```cpp
int side;
```

1 為藍方，-1 為紅方(可以用做座標轉換)

```cpp
intPair getBaseCoord(bool isAlly) const;
```

取得雙方基地座標

### 傳入值

- bool 我方( true ) 敵方 ( false )

### 回傳值

- intPair(x, y) 座標

```cpp
std::vector<int> monsterNearBy(intPair coord, int range) const;
std::vector<int> enemyNearBy(intPair coord, int range) const;
std::vector<int> allyNearBy(intPair coord, int range) const;
std::vector<int> shieldedMonsterNearBy(intPair coord, int range) const;
```

取得指定座標範圍內之各種實體，以距離排序

### 傳入值

- intPair(x, y) 座標
- int 範圍

### 回傳值

- std::vector<int> 實體 ID 之 vector

```cpp
void resetEntity();
```

清除所有實體映射 ( map )

```cpp
void setDefaultCoord(intPair allyCoord1, intPair allyCoord2, intPair allyCoord3);
```

設定所有 Ally 之預設座標

### 傳入值

- intPair(x, y) 三組座標依序對應 Ally

```cpp
intPair getDefaultCoord(int id);
```

取得該 ID 對應 Ally 之預設座標

### 傳入值

- int Ally 之 ID

### 回傳值

- intPair(x, y) 座標

```cpp
Player(int baseX, int baseY, int heroes);
```

建構子

### 傳入值

- int baseX, baseY 己方主堡位置
- int 英雄總數

```cpp
std::istream &operator>>(std::istream &is, Player &player);
```

進行回合輸入之運算子多載

### 運算元

- std::istream 左運算元
- Player& 右運算元 ( 玩家本身 )