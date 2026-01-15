#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    double w, v, a, d, l;
    cin >> a >> v >> l >> d >> w;

    double t1 = w / a;
    double t2 = v / a;
    double t3 = (v - w) / a;

    double s1 = w * t1 / 2.0;
    double s2 = v * t2 / 2.0;
    double s3 = (w + v) * t3 / 2.0;

    double ans = 0.0;

    if (w >= v || s1 >= d) {
        if (s2 >= l) {
            ans += sqrt(2.0 * l / a);
        } else {
            ans += t2;
            ans += (l - s2) / v;
        }
    } else {
        if (s2 + s3 <= d) {
            ans += t2 + t3;
            ans += (d - s2 - s3) / v;
        } else {
            double v0 = sqrt((d - s1) * a + w * w);
            ans += v0 / a;
            ans += (v0 - w) / a;
        }

        if (s3 <= l - d) {
            ans += t3;
            ans += (l - d - s3) / v;
        } else {
            double v1 = sqrt(2.0 * a * (l - d) + w * w);
            ans += (v1 - w) / a;
        }
    }

    cout << fixed << setprecision(5) << ans << '\n';
    return 0;
}
