#ifndef ZIPPED_STREAM_H
#define ZIPPED_STREAM_H

#include <iostream>
#include <sstream>

namespace conc {

class zipped_stream {
public:
    /// constructor
    explicit zipped_stream(std::ostream& os=std::cout);
    
    /// destructor
    ~zipped_stream();
    
    /// templated << operator
    template <typename Serializable>
    zipped_stream& operator<<(const Serializable& v);
    
    /// io manipulator << operator 
    zipped_stream& operator<<(std::ostream& (*iom)(std::ostream&));

private:
    std::ostream& os;
    std::stringstream ss;
};

typedef zipped_stream zstream;

} // namespace conc

#include "zipped_stream.hpp"

#endif // ZIPPED_STREAM_H
