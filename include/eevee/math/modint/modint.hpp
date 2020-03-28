#pragma once
#include <cstdint>
#include <iostream>
#include <utility>

namespace eevee {
template <std::uint_fast64_t Modulus> class Modint {
    using u64 = std::uint_fast64_t;

public:
    u64 num;

    constexpr Modint(const u64 x = 0) noexcept
        : num(x % Modulus) {}
    constexpr u64 &value() noexcept { return num; }
    constexpr const u64 &value() const noexcept { return num; }

    /* operator */
    constexpr Modint operator+(const Modint &rhs) const noexcept {
        return Modint(*this) += rhs;
    }
    constexpr Modint operator-(const Modint &rhs) const noexcept {
        return Modint(*this) -= rhs;
    }
    constexpr Modint operator*(const Modint &rhs) const noexcept {
        return Modint(*this) *= rhs;
    }
    constexpr Modint operator/(const Modint &rhs) const noexcept {
        return Modint(*this) /= rhs;
    }
    constexpr Modint &operator+=(const Modint &rhs) noexcept {
        num += rhs.num;
        if (num >= Modulus) {
            num -= Modulus;
        }
        return *this;
    }
    constexpr Modint &operator-=(const Modint &rhs) noexcept {
        if (num < rhs.num) {
            num += Modulus;
        }
        num -= rhs.num;
        return *this;
    }
    constexpr Modint &operator*=(const Modint &rhs) noexcept {
        num = num * rhs.num % Modulus;
        return *this;
    }
    constexpr Modint &operator/=(Modint &rhs) noexcept {
        *this *= rhs.inverse();
        return *this;
    }
    constexpr bool operator==(const Modint &rhs) const {
        return num == rhs.num;
    }
    constexpr bool operator!=(const Modint &rhs) const {
        return num != rhs.num;
    }

    /* friend */
    friend std::ostream& operator<<(std::ostream& os, const Modint& rhs) {
        return os << rhs.num;
    }
    friend std::istream &operator>>(std::istream &is, Modint &rhs) {
        u64 t;
        is >> t;
        rhs = Modint<Modulus>(t);
        return (is);
    }

    static u64 getMod() { return Modulus; }

    Modint pow(u64 n) const {
        Modint ret(1), mul(n);
        while (n > 0) {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    Modint inverse() const {
        u64 a = num, b = Modulus, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return Modint(u);
    }
};
} // namespace eevee
