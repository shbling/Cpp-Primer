#include "wy_conststrblobptr.h"


/**
 *  Return a shared_ptr,if the vector still available and the index within
 *  the range [first, last)
 */
std::shared_ptr<wy_ConstStrBlobPtr::tp>
wy_ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    std::shared_ptr<tp>
            result = wp.lock();

    if(!result)
        throw   std::runtime_error("unbound.");

    if(i >= result->size())
        throw   std::out_of_range(msg);

    return result;
}


/**
 * return the const string of the current index.
 */
const std::string &
wy_ConstStrBlobPtr::dereference() const
{
    std::shared_ptr<tp>
            sp = check(curr, "the index is out of range");

    return (*sp)[curr];
}


/**
 * increment the current index.
 */
wy_ConstStrBlobPtr &
wy_ConstStrBlobPtr::incr()
{
    check(curr, "out of range");
    ++curr;

    return *this;
}
