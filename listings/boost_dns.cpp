#include <iostream>
#include <map>
#include <string>
#include <mutex>
#include <boost/thread/shared_mutex.hpp>

class dns_entry {
public:
    dns_entry(int ip_=-1) : ip(ip_) {}

    friend bool operator==(const dns_entry& lhs, const dns_entry& rhs) {
        return lhs.ip == rhs.ip;
    }

private:
    int ip;
};

class dns_cache {
public:
    dns_entry find_entry(const std::string& domain) const {
        // multiple threads will share this lock
        boost::shared_lock<boost::shared_mutex> lk(entry_mutex);
        const auto it = entries.find(domain);
        return (it == entries.end()) ? dns_entry() : it->second;
    }

    void updated_or_add_entry(const std::string& domain, const dns_entry &dns) {
        // only one thread will own this lock
        std::lock_guard<boost::shared_mutex> lk(entry_mutex);
        entries[domain] = dns;
    }

private:    
    std::map<std::string, dns_entry> entries;
    mutable boost::shared_mutex entry_mutex;
};


int main() {
    dns_cache cache;
}
