namespace conc {

zipped_stream::zipped_stream(std::ostream& os_) : os(os_) {}

zipped_stream::~zipped_stream() {
    os << ss.str();
}

template <typename Serializable>
zipped_stream& zipped_stream::operator<<(const Serializable& v) {
    ss << v;
    return *this;
}

zipped_stream& zipped_stream::operator<<(std::ostream& (*iom)(std::ostream&)) {
    ss << iom;
    return *this;
}

} // namespace conc
