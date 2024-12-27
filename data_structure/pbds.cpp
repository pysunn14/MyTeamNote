#include "../setting/template.h"
//PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
                                    // less_equal : multi set
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

ordered_set OS;
void m_erase(ordered_set &OS, int val)
{
    int index = OS.order_of_key(val);
    auto it = OS.find_by_order(index);
    if (*it == val) OS.erase(it);
}