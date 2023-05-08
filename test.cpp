#include <bits/stdc++.h>
using namespace std;

void Mid_Point(int x_1, int y_1, int x_2, int y_2)
{
    int dx = x_2 - x_1;
    int dy = y_2 - y_1;
    if (dy <= dx)
    {
        int d = dy - (dx / 2);
        int first_pt = x_1;
        int second_pt = y_1;

        cout << first_pt << "," << second_pt << "\n";
        while (first_pt < x_2)
        {
            first_pt++;
            if (d < 0)
            {
                d = d + dy;
            }
            else
            {
                d = d + (dy - dx);
                second_pt++;
            }
            cout << first_pt << "," << second_pt << "\n";
        }
    }
    else if (dx < dy)
    {
        int d = dx - (dy / 2);
        int first_pt = x_1;
        int second_pt = y_1;
        cout << first_pt << "," << second_pt << "\n";
        while (second_pt < y_2)
        {
            second_pt++;
            if (d < 0)
            {
                d = d + dx;
            }
            else
            {
                d += (dx - dy);
                first_pt++;
            }
            cout << first_pt << "," << second_pt << "\n";
        }
    }
}
int main()
{
    int x_1 = 1;
    int y_1 = 12;
    int x_2 = 8;
    int y_2 = 4;
    cout << "Mid-Points through Line Generation Algorithm are: ";
    Mid_Point(x_1, y_1, x_2, y_2);
    return 0;
}