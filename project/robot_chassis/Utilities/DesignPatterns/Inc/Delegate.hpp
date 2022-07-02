#ifndef DESIGNED_PATTERN_DELEGATE_H
#define DESIGNED_PATTERN_DELEGATE_H

// we have C++11 support...yeah!

namespace DesignedPattern
{
/**
 * non specialized template declaration for delegate
 */
template <typename T>
class delegate;

/**
 * specialization for member functions
 *
 * \tparam T            class-type of the object who's member function to call
 * \tparam R            return type of the function that gets captured
 * \tparam params       variadic template list for possible arguments
 *                      of the captured function
 */
template <typename T, typename R, typename... Params>
class delegate<R (T::*)(Params...)>
{
public:
    typedef R (T::*func_type)(Params...);

    delegate(func_type func, T& callee)
        : callee_(callee)
        , func_(func)
    {}

    R operator()(Params... args) const
    {
        return (callee_.*func_)(args...);
    }

    bool operator==(const delegate& other) const
    {
        return (&callee_ == &other.callee_) && (func_ == other.func_);
    }
    bool operator!= (const delegate& other) const
    {
        return !((*this) == other);
    }

private:
    T& callee_;
    func_type func_;
};

/**
 * specialization for const member functions
 */
template <typename T, typename R, typename... Params>
class delegate<R (T::*)(Params...) const>
{
public:
    typedef R (T::*func_type)(Params...) const;

    delegate(func_type func, const T& callee)
        : callee_(callee)
        , func_(func)
    {}

    R operator()(Params... args) const
    {
        return (callee_.*func_)(args...);
    }

    bool operator==(const delegate& other) const
    {
        return (&callee_ == &other.callee_) && (func_ == other.func_);
    }
    bool operator!= (const delegate& other) const
    {
        return !(*this == other);
    }

private:
    const T& callee_;
    func_type func_;
};

/**
 * specialization for free functions
 *
 * \tparam R            return type of the function that gets captured
 * \tparam params       variadic template list for possible arguments
 *                      of the captured function
 */
template <typename R, typename... Params>
class delegate<R (*)(Params...)>
{
public:
    typedef R (*func_type)(Params...);

    delegate(func_type func)
        : func_(func)
    {}

    R operator()(Params... args) const
    {
        return (*func_)(args...);
    }

    bool operator==(const delegate& other) const
    {
        return func_ == other.func_;
    }
    bool operator!= (const delegate& other) const
    {
        return !((*this) == other);
    }

private:
    func_type func_;
};

/**
 * function to deduce template parameters from call-context
 */
template <typename F, typename T>
delegate<F> makeDelegate(F func, T& obj)
{
    return delegate<F>(func, obj);
}

template <typename T>
delegate<T> makeDelegate(T func)
{
    return delegate<T>(func);
}

/* a little backward compatilbility layer */
#define DELEGATE makeDelegate
#define DELEGATE_CONST makeDelegate
#define DELEGATE_FREE makeDelegate

} /* namespace DesignedPattern */

#endif // ! DESIGNED_PATTERN_DELEGATE_H
