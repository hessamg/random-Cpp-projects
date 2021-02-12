#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


struct User
{
    User(const std::string& _name) :
        name(_name), userCapacity(UINT_MAX) {
    }

    User(const std::string& _name,const unsigned& capacity):
        name(_name), userCapacity(capacity){}

    bool operator==(const User& other) const
    {
        return name == other.name;
    }

    std::string name;
    unsigned userCapacity;
};

struct MyHashFunction
{
    size_t operator()(const User& u) const
    {
        return (std::hash<std::string>()(u.name));
    }
};

class ResourceManager {
public:

    ResourceManager(const unsigned int& capacity) :
        resourceManagerCapacity(capacity), resourceManagerSize(1), dealocatesCount(0){}

    void addUser(const User& user)
    {
        users.insert(std::make_pair(user, 0));
    }

    std::string allocate(const std::string& user_name) {
        
        /*addToUser(user_name);*/
        if(resourceManagerSize > resourceManagerCapacity)
        {
            return "Error. RM has reached its maximum capacity";
        }
        ++users[user_name];
        const auto it = users.find(user_name);

        //std::cout << it->second << " " << it->first.name << " " <<it->first.userCapacity << " "<< resourceManagerSize << " "<< resourceManagerCapacity<<std::endl;
        if (it->second > it->first.userCapacity)
        {
            return "Error. " + it->first.name + " has reached their maximum capacity";
        }
        std::string res = "r";
        res.append(std::to_string(resourceManagerSize + dealocatesCount));
        ++resourceManagerSize;
        resources.emplace(std::make_pair(res, it->first.name));
        return res;
    }

    std::string deallocate(const std::string& resource_id) {
        const auto it = resources.find(resource_id);
        if(it == resources.end())
            return "Error";
        --users[it->second];
        --resourceManagerSize;
        ++dealocatesCount;
        resources.erase(resource_id);
        return "OK";
    }

    std::vector<std::string> list(const std::string& user_name) {
        std::vector<std::string> res;
        for (auto it = resources.begin(); it != resources.end(); it++) {
            if (it->second == user_name)
            {
                res.emplace_back(it->first);
            }
        }
        for (const auto r : res)
            std::cout << r << " ";
        std::cout << std::endl;
        return res;
    }

    void list() {
        std::string res;
        res.append("[");
        for (const auto& resource : resources)
        {
            res.append("(\"");
            res.append(resource.second);
            res.append("\", \"");
            res.append(resource.first);
            res.append("\"), ");
        }
        if (res.size() > 1)
        {
            res.pop_back();
            res.pop_back();
        }
        res.append("]");
        std::cout << res << std::endl;
    }

private:

    unsigned int resourceManagerCapacity;
    unsigned int resourceManagerSize;
    unsigned int dealocatesCount;
    std::unordered_map <User , int , MyHashFunction> users;
    std::unordered_map<std::string, std::string> resources;
};

int main(int argc, char* argv[])
{
    ResourceManager RM(5); 

    RM.addUser(User("alice", 2));
    RM.addUser(User("bob", 4));

    std::cout << RM.allocate("alice")<<std::endl; // "r1" # n = 1, m(alice) = 1
    std::cout << RM.allocate("bob") << std::endl; // "r2" # n = 2, m(bob) = 1
    std::cout << RM.allocate("bob") << std::endl; // "r3" # n = 3, m(bob) = 2
    std::cout << RM.allocate("alice") << std::endl; // "r4" # n = 4, m(alice) = 2
    std::cout << RM.allocate("alice") << std::endl; // error # n = 4, m(alice) = 2 (Alice has reached their maximum capacity)
    std::cout << RM.allocate("bob") << std::endl; // "r5" # n = 5, m(bob) = 3
    std::cout << RM.allocate("bob") << std::endl; // error # n = 5, m(bob) = 3 (RM has reached its maximum capacity)
    std::cout << RM.deallocate("r1") << std::endl; // ok # n = 4, m(alice) = 1
    std::cout <<RM.allocate("bob")<< std::endl; // "r6" # n = 5, m(bob) = 4
    std::cout << RM.allocate("carlos") << std::endl;// error # n = 5 (RM has reached it's maximum capacity)
    std::cout <<RM.deallocate("r3")<< std::endl; // ok # n = 4, m(bob) = 3
    std::cout <<RM.allocate("carlos")<< std::endl; // "r7" # n = 5
    std::cout <<RM.deallocate("r1")<< std::endl; // error # No resource with a given ID
    RM.list("bob"); // ["r2", "r5", "r6"]
    RM.list("charlie"); // []
    RM.list(); // [("bob", "r2"), ("alice", "r4"), ("bob", "r5"), ("bob", "r6"), ("carlos", "r7")

	return 0;
}