#include <iostream>
#include <string>

template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T>
class SecretVault
{
private:
    T secret;

public:
    SecretVault(T s) : secret(s) {}
    T getSecret() const
    {
        return secret;
    }

    T setScret(T newSecret)
    {
        secret = newSecret;
        return secret;
    }
};

int main()
{
    std::cout << "Adding integers:  " << add(5, 10) << std::endl;
    std::cout << "Adding doubles:  " << add(3.14, 2.71) << std::endl;

    SecretVault<std::string> vault("Top Secret Information");
    SecretVault<int> passwordVault(12345);

    std::cout << "Vault secret: " << vault.getSecret() << std::endl;
    std::cout << "Password vault secret: " << passwordVault.getSecret() << std::endl;

    return 0;
}