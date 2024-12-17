#include <iostream>
#include <string>
#include <cstdlib> // For system()
using namespace std;

namespace SiteSelector {
    struct Site {
        string name;
        string url;
    };

    // Predefined sites
    const Site sites[] = {
        {"Google", "https://www.google.com"},
        {"YouTube", "https://www.youtube.com"},
        {"GitHub", "https://github.com"},
        {"Wikipedia", "https://www.wikipedia.org"},
        {"LinkedIn","https://www.linkedin.com"},
        {"Instagram","https://www.instagram.com"},
        {"Whatsapp","https://www.whatsapp.com"},
        {"ChatGPT","https://chatgpt.com"},
        {"Microsoft","https://account.microsoft.com"},
        {"RNW React App","https://student.rnwmultimedia.com/"}
    };
    const int siteCount = sizeof(sites) / sizeof(sites[0]);

    void displaySites() {
        cout << "\nAvailable Sites:\n";
        for (int i = 0; i < siteCount; ++i) {
            cout << i + 1 << ". " << sites[i].name <<"\n";
        }
    }

    void openSiteInBrowser(int choice) {
        if (choice > 0 && choice <= siteCount) {
            string command = "start " + sites[choice - 1].url; // For Windows
            // For Linux/MacOS, use: std::string command = "xdg-open " + sites[choice - 1].url;
            cout << "Opening " << sites[choice - 1].name << " in your browser...\n";
            system(command.c_str());
        } else {
            cout << "Invalid selection. Please try again.\n";
        }
    }
}

int main() {
    using namespace SiteSelector;

    cout << "Welcome to the Site Selector!\n";
    displaySites();

    cout << "\nSelect a site to open (enter the number): ";
    int choice;
    cin >> choice;

    openSiteInBrowser(choice);

    return 0;
}

