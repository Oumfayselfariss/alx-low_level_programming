#include <string>

unsigned int binary_to_uint(const std::string& b)
{
    unsigned int uint = 0;
    unsigned int place = 1;

    for (int n = b.length() - 1; n >= 0; n--)
    {
        if (b[n] == '0')
        {
            place *= 2;
        }
        else if (b[n] == '1')
        {
            uint += place;
            place *= 2;
        }
        else
        {
            return 0;
        }
    }

    return uint;
}
