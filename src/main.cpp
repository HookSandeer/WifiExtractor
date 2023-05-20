// By Hooksander

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

void sleepFunction(int time) {
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(time));
}

void print(string text) {
    cout << text << endl;
}

void displayTitle() {
    print(" $$$$$$\\             $$\\                         $$\\                 $$$$$$$$\\             $$\\                                    $$\\                         ");
    print("$$  __$$\\            $$ |                        \\__|                $$  _____|            $$ |                                   $$ |                        ");
    print("$$ /  $$ |$$$$$$$\\ $$$$$$\\    $$$$$$\\  $$$$$$$\\  $$\\ $$$$$$$\\        $$ |      $$\\   $$\\ $$$$$$\\    $$$$$$\\  $$$$$$\\   $$$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\  ");
    print("$$$$$$$$ |$$  __$$\\_$$  _|  $$  __$$\\ $$  __$$\\ $$ |$$  __$$\\       $$$$$\\    \\$$\\ $$  |\\_$$  _|  $$  __$$\\ \\____$$\\ $$  _____|\\_$$  _|  $$  __$$\\ $$  __$$\\ ");
    print("$$  __$$ |$$ |  $$ | $$ |    $$ /  $$ |$$ |  $$ |$$ |$$ |  $$ |      $$  __|    \\$$$$  /   $$ |    $$ |  \\__|$$$$$$$ |$$ /        $$ |    $$ /  $$ |$$ |  \\__|");
    print("$$ |  $$ |$$ |  $$ | $$ |$$\\ $$ |  $$ |$$ |  $$ |$$ |$$ |  $$ |      $$ |       $$  $$<    $$ |$$\\ $$ |     $$  __$$ |$$ |        $$ |$$\\ $$ |  $$ |$$ |      ");
    print("$$ |  $$ |$$ |  $$ | \\$$$$  |\\$$$$$$  |$$ |  $$ |$$ |$$ |  $$ |      $$$$$$$$\\ $$  /\\$$\\   \\$$$$  |$$ |     \\$$$$$$$ |\\$$$$$$$\\   \\$$$$  |\\$$$$$$  |$$ |      ");
    print("\\__|  \\__|\\__|  \\__|  \\____/  \\______/ \\__|  \\__|\\__|\\__|  \\__|      \\________|\\__/  \\__|   \\____/ \\__|      \\_______| \\_______|   \\____/  \\______/ \\__|      ");
}

int main() {
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);      // FULL SCREEN CONSOLE WINDOW
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    displayTitle();

    print("\n\n\nAfficher cle activation systeme ? [o/n]");
    char usr;
    cin >> usr;
    cin.ignore();
    if(usr=='o'){
        print("\nCle d'activation du systeme actuelle :\n\n");
        sleepFunction(2);
        system("wmic path softwarelicensingservice get OA3xOriginalProductKey");
        sleepFunction(1);
        print("\n\nEntrer pour continuer.");
        cin.ignore();
    }

    print("\n\nAfficher wifi info ? [o/n]");
    cin >> usr;
    cin.ignore();
    if(usr=='o'){
        sleepFunction(1);
        system("netsh wlan show interfaces");
        string boxName;
        print("\nEntrer le nom de la box : ");
        getline(cin, boxName);
        string command = "netsh wlan show profiles " + boxName + " key=clear";
        const char* commandChar = command.c_str();
        print("\nChargement...\n");
        sleepFunction(2);
        system(commandChar);
    }

    sleepFunction(1);
    print("\nBoss j'espere ca ta aide, oublie pas de tout save et prepare KMS Pico");
    print("Appuie sur entrer et c'est tout bon");
    
    cin.ignore();
    return 0;
}