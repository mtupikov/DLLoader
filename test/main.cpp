#ifdef WIN32
#include "Win/DLLoader.h"
#else
#include "Unix/DLLoader.h"
#endif

#ifdef WIN32
const std::string testLibrary = "testLibrary.dll";
#endif
#ifdef __linux__
const std::string testLibrary = "./testLibrary.so";
#endif
#ifdef __APPLE__
const std::string testLibrary = "./testLibrary.dylib";
#endif

#include "TestInterface.h"

int	main() {
    dlloader::DLLoader<TestInterface> loader(testLibrary);

    if (!loader.openLibrary()) {
        std::cerr << "Cannot load " << testLibrary << " library." << std::endl;
        return -1;
    }

    auto instance = loader.getInstance();

    if (instance) {
        instance->function();
    }

	return 0;
}
