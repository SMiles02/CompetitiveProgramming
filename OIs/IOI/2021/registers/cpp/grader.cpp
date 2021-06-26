#include "registers.h"

#include <bitset>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>

#ifdef _MSC_VER
#   define NORETURN __declspec(noreturn)
#elif defined __GNUC__
#   define NORETURN __attribute__ ((noreturn))
#else
#   define NORETURN
#endif


static const int m = 100;
static const int b = 2000;
static const int id_move = 0;
static const int id_store = 1;
static const int id_and = 2;
static const int id_or = 3;
static const int id_xor = 4;
static const int id_not = 5;
static const int id_left = 6;
static const int id_right = 7;
static const int id_add = 8;
static const int id_print = 9;

static int s, n, k, q;
static int instruction_count = 0;
static std::bitset<b> reg[m];

static inline void load_register(std::bitset<b>& bs, std::vector<int>& v) {
    bs.reset();
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < k; j++) {
            bs[i * k + j] = (v[i] & (1 << j));
        }
    }
}

static inline void unload_register(std::bitset<b>& bs, std::vector<int>& v) {
    v.assign(v.size(), 0);
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < k; j++) {
            v[i] |= (bs[i * k + j] << j);
        }
    }
}

static void execute_move(int t, int x) {
    reg[t] = reg[x];
}

static void execute_store(int t, std::vector<bool> v) {
    for(int i=0; i<b; i++) {
        reg[t][i] = v[i]; // bit-by-bit copy
    }
}

static void execute_and(int t, int x, int y) {
    reg[t] = (reg[x]&reg[y]);
}

static void execute_or(int t, int x, int y) {
    reg[t] = (reg[x]|reg[y]);
}

static void execute_xor(int t, int x, int y) {
    reg[t] = (reg[x]^reg[y]);
}

static void execute_not(int t, int x) {
    reg[t] = (~reg[x]);
}

static void execute_left(int t, int x, int p) {
    reg[t] = (reg[x]<<p);
}

static void execute_right(int t, int x, int p) {
    reg[t] = (reg[x]>>p);
}

static void execute_add(int t, int x, int y) {
    std::bitset<b> tmp;
    bool carry = false;
    for(int i = 0; i < b; i++) {
        tmp[i] = (reg[x][i] ^ reg[y][i] ^ carry);
        carry = (reg[x][i] & reg[y][i]) || (reg[x][i] & carry) || (reg[y][i] & carry); // discard the last carry
    }
    reg[t] = tmp;
}

static void execute_print(int t) {
    std::vector<int> v(n);
    unload_register(reg[t], v);
    printf("register %d: ", t);
    for (int i = 0; i < n; i++) {
        printf("%d%c", v[i], i < n - 1 ? ' ' : '\n');
    }
}

struct instruction {
    int type, t, x, y;
    std::vector<bool> v;

    instruction(int _type): type(_type), t(-1), x(-1), y(-1) {}

    void execute() {
        switch(type) {
            case id_move:
                execute_move(t, x);
                break;
            case id_store:
                execute_store(t, v);
                break;
            case id_and:
                execute_and(t, x, y);
                break;
            case id_or:
                execute_or(t, x, y);
                break;
            case id_xor:
                execute_xor(t, x, y);
                break;
            case id_not:
                execute_not(t, x);
                break;
            case id_left:
                execute_left(t, x, y);
                break;
            case id_right:
                execute_right(t, x, y);
                break;
            case id_add:
                execute_add(t, x, y);
                break;
            case id_print:
                execute_print(t);
                break;
            default:
                assert(false);
        }
    }
    void print() {
        switch(type) {
            case id_move:
                printf("move %d %d\n", t, x);
                break;
            case id_store:
                printf("store %d ", t);
                for(int i=0; i<b; i++) {
                    putchar(v[i]+'0');
                }
                putchar('\n');
                break;
            case id_and:
                printf("and %d %d %d\n", t, x, y);
                break;
            case id_or:
                printf("or %d %d %d\n", t, x, y);
                break;
            case id_xor:
                printf("xor %d %d %d\n", t, x, y);
                break;
            case id_not:
                printf("not %d %d\n", t, x);
                break;
            case id_left:
                printf("left %d %d %d\n", t, x, y);
                break;
            case id_right:
                printf("right %d %d %d\n", t, x, y);
                break;
            case id_add:
                printf("add %d %d %d\n", t, x, y);
                break;
            case id_print:
                printf("print %d\n", t);
                break;
            default:
                assert(false);
        }
    }
};

static std::vector<instruction> instructions;

NORETURN static inline void error(std::string reason) {
    printf("%s\n", reason.c_str());
    fflush(stdout);
    exit(0);
}

static inline void check_instructions() {
    if (instruction_count >= q) {
        error("Too many instructions");
    }
}

static inline void check_index(int index) {
    if (index < 0 || index >= m) {
        error("Invalid index");
    }
}

void append_move(int t, int x) {
    check_instructions();
    check_index(t);
    check_index(x);
    instruction i(id_move);
    i.t = t;
    i.x = x;
    instruction_count++;
    instructions.push_back(i);
}

void append_store(int t, std::vector<bool> v) {
    check_instructions();
    check_index(t);
    if ((int)v.size() != b) {
        error("Value to store is not b bits long");
    }
    instruction i(id_store);
    i.t = t;
    i.v = v;
    instruction_count++;
    instructions.push_back(i);
}

void append_and(int t, int x, int y) {
    check_instructions();
    check_index(t);
    check_index(x);
    check_index(y);
    instruction i(id_and);
    i.t = t;
    i.x = x;
    i.y = y;
    instruction_count++;
    instructions.push_back(i);
}

void append_or(int t, int x, int y) {
    check_instructions();
    check_index(t);
    check_index(x);
    check_index(y);
    instruction i(id_or);
    i.t = t;
    i.x = x;
    i.y = y;
    instruction_count++;
    instructions.push_back(i);
}

void append_xor(int t, int x, int y) {
    check_instructions();
    check_index(t);
    check_index(x);
    check_index(y);
    instruction i(id_xor);
    i.t = t;
    i.x = x;
    i.y = y;
    instruction_count++;
    instructions.push_back(i);
}

void append_not(int t, int x) {
    check_instructions();
    check_index(t);
    check_index(x);
    instruction i(id_not);
    i.t = t;
    i.x = x;
    instruction_count++;
    instructions.push_back(i);
}

void append_left(int t, int x, int p) {
    check_instructions();
    check_index(t);
    check_index(x);
    if (p < 0 || p > b) {
        error("Invalid shift value");
    }
    instruction i(id_left);
    i.t = t;
    i.x = x;
    i.y = p;
    instruction_count++;
    instructions.push_back(i);
}

void append_right(int t, int x, int p) {
    check_instructions();
    check_index(t);
    check_index(x);
    if (p < 0 || p > b) {
        error("Invalid shift value");
    }
    instruction i(id_right);
    i.t = t;
    i.x = x;
    i.y = p;
    instruction_count++;
    instructions.push_back(i);
}

void append_add(int t, int x, int y) {
    check_instructions();
    check_index(t);
    check_index(x);
    check_index(y);
    instruction i(id_add);
    i.t = t;
    i.x = x;
    i.y = y;
    instruction_count++;
    instructions.push_back(i);
}

void append_print(int t) {
    check_index(t);
    instruction i(id_print);
    i.t = t;
    instructions.push_back(i);
}

int main() {
    assert(4 == scanf("%d %d %d %d", &s, &n, &k, &q));

    construct_instructions(s, n, k, q);
    for(instruction &i : instructions) {
        i.print();
    }
    std::vector<int> a(n);
    bool exited = false;
    while (true) {
        for (int i = 0; i < n; i++) {
            assert(1 == scanf("%d", &a[i]));
            if (i == 0 && a[i] == -1) {
                fflush(stdout);
                exited = true;
                break;
            }
        }
        if (exited) break;
        load_register(reg[0], a);
        for (int i = 1; i < m; i++) {
            reg[i].reset();
        }
        for (instruction& i : instructions) {
            i.execute();
        }
        unload_register(reg[0], a);
        if (s == 0) {
            printf("%d\n", a[0]);
        } else {
            for (int i = 0; i < n; i++) {
                printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
            }
        }
    }
    printf("number of instructions: %d\n", instruction_count);
    return 0;
}
