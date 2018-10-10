#include <iostream>
#include "picojson.h"
using namespace std;

template<typename First>
picojson::value test(picojson::value o, First first) {
    picojson::value obj = o.get<picojson::object>().at(first);
    return obj;
}
template<typename First, typename... Values>
picojson::value test(picojson::value o, First first, Values... value)
{
    picojson::value obj = o.get<picojson::object>().at(first);
    return test(obj,value...);
}

template<typename T, typename First, typename... Values>
T getValue(picojson::value v, First first, Values... value)
{
    picojson::value v2 = v.get<picojson::object>().at(first);
    picojson::value v3 = test(v2,value...);
    T t = v3.get<T>();
    return t;
}
