#include <iostream>
#include <tuple>

using namespace std;

int main() {

    // as good as a structure
    tuple<int, string, int> t;

    t = make_tuple(1, "a", 9);

    // 'get' happens at compile time so cannot have them in a loop
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << endl;

    cout << tuple_size<decltype(t)>::value << endl;
    string s;
    int x, y, z;
    tie(x, s, y) = t;

    cout << x << " " << s << " " << y << endl;
    s = "";
    tie(z, s, ignore) = t;
    cout << z << " " << s << endl;

    tuple<char, string> v = make_tuple('m', "tv");
    auto m = tuple_cat(t, v);

    cout << get<0>(m) << " " << get<1>(m) << " " << get<2>(m) << " " << get<3>(m) << " " << get<4>(m) << " " << endl;
}