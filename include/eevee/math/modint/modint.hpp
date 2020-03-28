#pragma once
#include <cstdint>
#include <iostream>
#include <utility>

namespace eevee {
template <std::int_fast64_t Modulus> class ModInt {
    using i64 = std::int_fast64_t;

public:
    i64 num;

    constexpr ModInt(const i64 x = 0) noexcept
        : num(x>=0 ? x % Modulus : (Modulus - (-x) % Modulus ) % Modulus) {}
    constexpr i64 &value() noexcept { return num; }
    constexpr const i64 &value() const noexcept { return num; }

    /* operator */
    constexpr ModInt operator-() const noexcept { return ModInt(-num); }
    constexpr ModInt operator+(const ModInt &rhs) const noexcept {
        return ModInt(*this) += rhs;
    }
    constexpr ModInt operator-(const ModInt &rhs) const noexcept {
        return ModInt(*this) -= rhs;
    }
    constexpr ModInt operator*(const ModInt &rhs) const noexcept {
        return ModInt(*this) *= rhs;
    }
    constexpr ModInt operator/(const ModInt &rhs) const noexcept {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt &operator+=(const ModInt &rhs) noexcept {
        if ((num += rhs.num) >= Modulus) num -= Modulus;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) noexcept {
        if ((num += Modulus - rhs.num) >= Modulus) num -= Modulus;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) noexcept {
        num = static_cast<i64>(1LL * num * rhs.num % Modulus);
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) noexcept {
        (*this) *= rhs.inverse();
        return *this;
    }

    constexpr bool operator==(const ModInt &rhs) const {
        return num == rhs.num;
    }
    constexpr bool operator!=(const ModInt &rhs) const {
        return num != rhs.num;
    }

    /* friend */
    friend std::ostream& operator<<(std::ostream& os, const ModInt& rhs) {
        return os << rhs.num;
    }
    friend std::istream &operator>>(std::istream &is, ModInt &rhs) {
        i64 t;
        is >> t;
        rhs = ModInt<Modulus>(t);
        return (is);
    }

    static i64 getMod() { return Modulus; }

    ModInt pow(i64 n) const {
        i64 a = 1, p = num;
        while (n > 0) {
            if (n % 2 == 0) {
                p = (p * p) % Modulus; 
                n /= 2;
            }
            else {
                a = (a * p) % Modulus;
                n--;
            }
        }
        return ModInt(a);
    }
    ModInt& operator^(i64 n) {
        *this = (*this).pow(n);
        return *this;
    }

    ModInt inverse() const {
        i64 a = num;
        i64 b = Modulus, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        return ModInt(u);
    }

};
} // namespace eevee
