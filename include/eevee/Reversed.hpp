#pragma once
#include <iterator>
#include <utility>
#include <tuple>

namespace eevee {
template <typename Range,
		  typename reversed_iterator = decltype(std::declval<Range>().rbegin()),
		  typename = decltype(std::declval<Range>().rend())>
constexpr auto Reversed(Range&& range) {
	struct iterator {
		reversed_iterator iter;
		bool operator!= (const iterator& end) const { return iter != end.iter; }
		/* auto& */ void operator++() { ++iter; /* return iter; */ }
		auto& operator*() const { return *iter; }
	};
	struct iterator_wrapper {
		Range iterable;
		auto begin() {
			return iterator{ iterable.rbegin() };
		}
		auto end() { 
			return iterator{ iterable.rend() };
		}
	};
	return iterator_wrapper{ std::forward<Range>(range) };
}
}

template <typename Range>
constexpr auto reversed_inm(Range&& range) {
    static_assert(std::is_lvalue_reference_v<Range>);

    using std::rbegin;
    using std::rend;
    using reverse_iterator = decltype(rbegin(range));
    using sentinel_type = decltype(rend(range));

	struct sentinel {
		sentinel_type iter;
	};

	struct iterator {
		reverse_iterator iter;
		bool operator!= (const sentinel& end) const { return iter != end.iter; }
		auto& operator++() { ++iter; return *iter; }
		auto& operator*() const { return *iter; }
	};
	struct iterator_wrapper {
		Range iterable;
		auto begin() {
            return iterator{ rbegin(iterable) };
        }
		auto end() {
            return sentinel{ rend(iterable) };
        }
	};
	return iterator_wrapper{ std::forward<Range>(range) };
}
