#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

class ClientProject
{
public:
    std::string name;
    int budget;

    ClientProject(std::string name, int budget) : name(name), budget(budget)
    {
        std::cout << "[System] new project aquired: " << name << " with budget " << budget << std::endl;
    }

    ~ClientProject()
    {
        std::cout << "[System] project " << name << " completed and removed from the system" << std::endl;
    }
};

class Engineer
{
public:
    std::string name;
    std::vector<std::unique_ptr<ClientProject>> projects;

    Engineer(std::string name) : name(name)
    {
        std::cout << "[System} new engineer hired: " << name << std::endl;
    }

    ~Engineer()
    {
        std::cout << "[System] engineer " << name << " has left the company" << std::endl;
    }

    void assignProject(std::unique_ptr<ClientProject> project)
    {
        std::cout << "[System] assigning project " << project->name << " to engineer " << name << std::endl;
        projects.push_back(std::move(project));
    }

    void printStatus() const
    {
        std::cout << "Engineer: " << name << std::endl;
        std::cout << "Active Projects: " << projects.size() << std::endl;

        int totalRevenue = 0;

        for (const auto &project : projects)
        {
            std::cout << "* Client name: " << project->name << " | Budget: " << project->budget << std::endl;
            totalRevenue += project->budget;
        }

        std::cout << "Total Revenue from projects: " << totalRevenue << std::endl;
    }
};

int main()
{
    std::cout << "Booting up the agency engine..." << std::endl;

    std::unordered_map<std::string, std::unique_ptr<Engineer>> agencyDb;

    agencyDb["Satpal"] = std::make_unique<Engineer>("Satpal");
    agencyDb["Aadarsh"] = std::make_unique<Engineer>("Aadarsh");
    agencyDb["Raj"] = std::make_unique<Engineer>("Raj");

    agencyDb["Raj"]->assignProject(std::make_unique<ClientProject>("ScriptWeaver Upgrade", 5000));
    agencyDb["Satpal"]->assignProject(std::make_unique<ClientProject>("React.js Ecommerce UI", 3000));
    agencyDb["Aadarsh"]->assignProject(std::make_unique<ClientProject>("Next.js Saas Backend", 4500));
    agencyDb["Satpal"]->assignProject(std::make_unique<ClientProject>("Electron Desktop Port", 2500));

    std::cout << "\n--- Agency Status ---\n"
              << std::endl;
    for (const auto &entry : agencyDb)
    {
        entry.second->printStatus();
        std::cout << "----------------------\n"
                  << std::endl;
    }

    std::cout << "Shutting down the agency engine..." << std::endl;
    return 0;
}