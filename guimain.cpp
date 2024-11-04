#include <string>
#include <vector>

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

//Buy and Destroy building functions

static std::vector<std::string> buildings;
static std::vector<std::string> utilities;
static std::vector<std::string> services;

void makebuilding () {
    buildings.push_back("building");
}
void makeUtility () {
    utilities.push_back("utility");
}
void makeservice () {
    services.push_back("service");
}

void destroybuilding() {
    buildings.pop_back();
}

void destroyutility() {
    utilities.pop_back();
}

void destroyservice() {
    services.pop_back();
}

void buyfunc(bool* showBuyWindow,bool* showBuildingWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Buying Building Window");

    ImGui::Text("You have bought a building");

    if (ImGui::Button("Close Window")) {
        *showBuyWindow = false;
        *showBuildingWindow = false;
    }

    ImGui::End();
}

void desfunc(bool* showDestroyWindow,bool* showBuildingWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Destroying Building Window");

    ImGui::Text("You have destroyed a building");

    if (ImGui::Button("Close Window")) {
        *showDestroyWindow = false;
        *showBuildingWindow = false;
    }

    ImGui::End();
}
//Buy and Destroy building functions

//Buy and Destroy Utilities functions
void buyUtil(bool* showBuyWindow,bool* showBuildingWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Buying Utility Window");

    ImGui::Text("You have bought a Utility");

    if (ImGui::Button("Close Window")) {
        *showBuyWindow = false;
        *showBuildingWindow = false;
    }

    ImGui::End();
}

void destroyUtil(bool* showDestroyWindow,bool* showBuildingWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Destroying Utility Window");

    ImGui::Text("You have destroyed a Utility");

    if (ImGui::Button("Close Window")) {
        *showDestroyWindow = false;
        *showBuildingWindow = false;
    }

    ImGui::End();
}
//Buy and Destroy Utilities functions

//buy destroy services
void buyService(bool* showBuyWindow,bool* showBuildingWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Buying Service Window");

    ImGui::Text("You have bought a Service");

    if (ImGui::Button("Close Window")) {
        *showBuyWindow = false;
        *showBuildingWindow = false;
    }

    ImGui::End();
}

void destroyService(bool* showDestroyWindow,bool* showBuildingWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Destroying Service Window");

    ImGui::Text("You have destroyed a Service");

    if (ImGui::Button("Close Window")) {
        *showDestroyWindow = false;
        *showBuildingWindow = false;
    }

    ImGui::End();
}
//buy destroy services

//tax rate and strat

void changetaxRate(bool* showWindow, double* out) {
    ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Always);
    double rate;

    ImGui::Begin("Change Rate Window");

    if (ImGui::InputDouble("Input Rate", &rate)) {
        *out = rate;
    }
    if(ImGui::Button("close window")) {

        *showWindow = false;
    }
    ImGui::End();
}

void changetaxStrat(bool* showWindow,char* out) {
    ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Always);
    char* items[] = { "Flat", "Progressive", "Regressive" };
    int Itemindex = 0;  // Index of the selected item

    ImGui::Begin("Change Rate Window");

    if (ImGui::Combo("Dropdown", &Itemindex, items, IM_ARRAYSIZE(items))) {
        out = new char(*items[Itemindex]);
    }
    if(ImGui::Button("close window")) {
        *showWindow = false;
    }
    ImGui::End();
}

//tax rate and strat

//transport rate and strat

void changetransportRate(bool* showWindow, double* out) {
    ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Always);
    double rate;

    ImGui::Begin("Change Rate Window");

    if (ImGui::InputDouble("Input Rate", &rate)) {
        *out = rate;
    }
    if(ImGui::Button("close window")) {

        *showWindow = false;
    }
    ImGui::End();
}

void changetransportStrat(bool* showWindow,char* out) {
    ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Always);
    const char* items[] = { "Flat", "Progressive", "Regressive" };
    int Itemindex = 0;  // Index of the selected item

    ImGui::Begin("Change strategy Window");

    if (ImGui::Combo("Dropdown", &Itemindex, items, IM_ARRAYSIZE(items))) {
        out = new char(*items[Itemindex]);
    }
    if(ImGui::Button("close window")) {
        *showWindow = false;
    }
    ImGui::End();
}

//transport rate and strat

// Main Building Window
void BuildingWindow(bool* showBuildingWindow, bool* showBuyWindow, bool* showDestroyWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Building Window");

    ImGui::Text("Are you buying or destroying a building");

    if (ImGui::Button("Buy")) {
        makebuilding();
        *showBuyWindow = true;
    }

    if (ImGui::Button("Destroy")) {
        destroybuilding();
        *showDestroyWindow = true;
    }

    if (ImGui::Button("Close Window")) {
        *showBuildingWindow = false;
    }

    ImGui::End();
}

void UtilityWindow(bool* showBuildingWindow, bool* showBuyWindow, bool* showDestroyWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Utility Window");

    ImGui::Text("Are you buying or destroying a Utility");

    if (ImGui::Button("Buy")) {
        makeUtility();
        *showBuyWindow = true;
    }

    if (ImGui::Button("Destroy")) {
        destroyutility();
        *showDestroyWindow = true;
    }

    if (ImGui::Button("Close Window")) {
        *showBuildingWindow = false;
    }

    ImGui::End();
}

void ServiceWindow(bool* showWindow, bool* showBuyWindow, bool* showDestroyWindow) {
    ImGui::SetNextWindowSize(ImVec2(600, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    ImGui::Begin("Service Window");

    ImGui::Text("Are you buying or destroying a Service");

    if (ImGui::Button("Buy")) {
        makeservice();
        *showBuyWindow = true;
    }

    if (ImGui::Button("Destroy")) {
        destroyservice();
        *showDestroyWindow = true;
    }

    if (ImGui::Button("Close Window")) {
        *showWindow = false;
    }

    ImGui::End();
}

void TaxWindow(bool* showWindow,bool* rateWindow,bool* stratWindow) {
    ImGui::SetWindowSize(ImVec2(600,200),ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100,100),ImGuiCond_Always);
    ImGui::Begin("Tax Window");

    ImGui::Text("What would you like to change");

    if(ImGui::Button("change Tax rate")) {
        *rateWindow = true;
    }

    if(ImGui::Button("change Tax Strategy")) {
        *stratWindow = true;
    }
    if (ImGui::Button("Close Window")) {
        *showWindow = false;
    }
    ImGui::End();
}

void TransportWindow(bool* showWindow,bool* rateWindow , bool* stratWindow) {
    ImGui::SetWindowSize(ImVec2(600,200),ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(100,100),ImGuiCond_Always);
    ImGui::Begin("Transport Window");

    ImGui::Text("What would you like to change");

    if(ImGui::Button("change Transport rate")) {
        *rateWindow = true;
    }

    if(ImGui::Button("change Transport Strategy")) {
        *stratWindow = true;
    }
    if (ImGui::Button("Close Window")) {
        *showWindow = false;
    }
    ImGui::End();
}



const char* concat (const char* c,std::string s, double in) {
    std::string out = s+" "+std::to_string(in);
    c = out.c_str();
    return c;
}

double citizensatisfaction(double i, double s) {
    double satisfaction = 100*(1-i)+50*s;
    return satisfaction;
}

void citizengrowth(int* i) {
    *i+=1.5*utilities.size()+1.2*services.size()+2*buildings.size();
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "ImGui Window", nullptr, nullptr);
    if (!window) return -1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");



    bool showBuildingWindow = false;
    bool showBuyWindow = false;
    bool showDestroyWindow = false;
    bool showUtilityWindow = false;
    bool showServiceWindow = false;
    bool showTransportWindow = false;
    bool showTaxWindow = false;
    bool showProgressWindow = false;
    bool showTaxrate = false;
    bool showTaxStrat = false;
    bool showTranspRate = false;
    bool showTranspStrat = false;

    double* taxrate = new double(0.1175);
    auto taxstrat = new char('No strategy is set');
    double* transprate = new double(0.15);
    auto transpstrat = new char('No strategy is set');
    int citizens = 100;
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        std::string s = "citizens:";
        const char* str ;
        const char* trate;
        // Main menu window
        ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Always);
        ImGui::Begin("Hello, ImGui!");


        if(ImGui::Button("Progress year")) {
            showProgressWindow = true;
        }

        if(showProgressWindow) {
            ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Always);
            ImGui::Begin("Progress window");
            ImGui::Text("hello world");

            if (ImGui::Button("Open Building Window")) {
                showBuildingWindow = true;
            }

            if (ImGui::Button("Open Utility Window")) {
                showUtilityWindow = true;
            }

            if (ImGui::Button("Open Service Window")) {
                showServiceWindow = true;
            }
            if (ImGui::Button("Open tax Window")) {
                showTaxWindow = true;
            }
            if (ImGui::Button("Open Transport Window")) {
                showTransportWindow = true;
            }
            if (ImGui::Button("Close Window")) {
                showProgressWindow = false;
                citizengrowth(&citizens);

            }



            // Render windows based on flags
            if (showBuildingWindow) {
                BuildingWindow(&showBuildingWindow, &showBuyWindow, &showDestroyWindow);
                if (showBuyWindow) {
                    buyfunc(&showBuyWindow,&showBuildingWindow);
                }

                if (showDestroyWindow) {
                    desfunc(&showDestroyWindow,&showBuildingWindow);
                }
            }
            //render util
            if (showUtilityWindow) {
                UtilityWindow(&showUtilityWindow, &showBuyWindow, &showDestroyWindow);
                if (showBuyWindow) {
                    buyUtil(&showBuyWindow, &showUtilityWindow);
                }

                if (showDestroyWindow) {
                    destroyUtil(&showDestroyWindow,&showUtilityWindow);
                }
            }
            //render Service

            if (showServiceWindow) {
                ServiceWindow(&showServiceWindow, &showBuyWindow, &showDestroyWindow);
                if (showBuyWindow) {
                    buyService(&showBuyWindow, &showServiceWindow);
                }

                if (showDestroyWindow) {
                    destroyService(&showDestroyWindow,&showServiceWindow);
                }
            }
            //tax window
            if(showTaxWindow) {
                TaxWindow(&showTaxWindow,&showTaxrate,&showTaxStrat);
                if(showTaxrate) {
                    changetaxRate(&showTaxrate,taxrate);
                }
                if(showTaxStrat) {
                    changetaxStrat(&showTaxStrat,taxstrat);
                }

            }
            //transport window
            if(showTransportWindow) {
                TransportWindow(&showTransportWindow,&showTranspRate,&showTranspStrat);
                if(showTranspRate) {
                    changetaxRate(&showTranspRate,transprate);
                }
                if(showTranspStrat) {
                    changetaxStrat(&showTranspStrat,transpstrat);
                }
            }
            ImGui::End();
        }

        ImGui::Text(concat(str,s,citizens));
        ImGui::Text(concat(trate,"tax rate: ",*taxrate));
        ImGui::Text("tax Strat: ",taxstrat);
        ImGui::Text(concat(trate,"tax rate: ",*transprate));
        ImGui::Text("tax Strat: ",transpstrat);
        ImGui::Text(concat(trate,"Number of buildings",buildings.size()));
        ImGui::Text(concat(trate,"Number of utilities",utilities.size()));
        ImGui::Text(concat(trate,"Number of services",services.size()));
        ImGui::Text(concat(trate,"citizen satisfaction:",citizensatisfaction(*taxrate,*transprate)));

        ImGui::End();
        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    delete taxrate;

    return 0;
}