
#include "mainwin.h"
#include <sstream>
#include "entrydialog.h"
#include <iostream> // for std::cerr logging
#include <iomanip>
#include <fstream>

Mainwin::Mainwin() :store{new Store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
   
    set_default_size(800, 800);
    set_title("ELSA");
   

    
    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);
	
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
	//FILE menu item
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

        Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);

    //         S A V E   G A M E
    // Append Save As... to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save ", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);
    //         S A V E ---- A S
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);

    //         O P E N   G A M E
    // Append Open... to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);
    //// QUIT
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //////////////
    //VIEW menu item
    /////////////


    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    Gtk::MenuItem *menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_peripheral);

    Gtk::MenuItem *menuitem_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_desktop);

    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_order);

    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_customer);
    ///////////////
    //INSERT menu item
    ////////////////
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));   
    menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    insertmenu->append(*menuitem_insert_peripheral);
  //   menuitem_insert_peripheral->show();


     Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_insert_desktop);
    //menuitem_insert_desktop->show();


     Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_insert_order);


     Gtk::MenuItem *menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("_customer", true));
    menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem_insert_customer);



    ////////////////////
    //HELP menu item
    //////////////////
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);
    
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

  
    data = Gtk::manage(new Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START});
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);
    set_data("WELCOME TO MY STORE FOR SPRINT 3\n\nHow can i help you today?");

    

     msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    vbox->show_all();
}
//VIEW
void Mainwin::on_view_peripheral_click()
{
     std::ostringstream oss;
     oss<<"PERIPHERAL LIST:\n\n";

            for(int i=0; i<store->num_options(); ++i) 
              oss<< i << ") " << store->option(i) << "\n";
                set_data(oss.str());
}

void Mainwin::on_view_desktop_click()
{
    std::ostringstream oss;
    oss<<"DESKTOP LIST:\n\n";
      for(int i=0; i<store->num_desktops(); ++i) 
                    oss<< i << ") " << store->desktop(i) << "\n";
    set_data(oss.str());
}
void Mainwin::on_view_customer_click()
{
       std::ostringstream oss;
       oss<<"CUSTOMER LIST:\n\n";
        for(int i=0; i<store->num_customers(); ++i) 
        {
                oss << i << ") " << store->customer(i) << "\n";      
        }
   
        set_data(oss.str());
     
}
void Mainwin::on_view_order_click()
{
    std::ostringstream oss;
    oss <<"ORDER PLACED:\n\n";
    for(int i=0; i<store->num_orders(); ++i) 
     oss<< i << ") " << store->order(i) << "\n";
     set_data(oss.str());
}
void Mainwin::on_quit_click()
{
	close();
}
///INSERT
void Mainwin::on_insert_peripheral_click()
{
    std::string name = "Product Name";
    std::string num  = "Product Cost";
    std::string e_name = get_string(name);
    std::string e_cost = get_string(num);
    double cost = get_double(e_cost);
    Options option{e_name,cost};
  
    store->add_option(option);
    on_view_peripheral_click();
}

void Mainwin::on_insert_desktop_click()
{   on_view_peripheral_click();  
    int desktop = store->new_desktop();
    while(true)
    {
    std::string text = "Add which Peripheral. -1 to stop";
    std::string ans = get_string(text);
    int option = get_int(ans);
    if(option == -1){break;}
     try {
            store->add_option(option, desktop);
         } 
    catch(std::exception& e) 
            {
                std::cerr << "#### INVALID OPTION ####\n\n";
             }
    }
    on_view_desktop_click();
    set_msg("Added desktop " + std::to_string(desktop));
}
void Mainwin::on_insert_order_click()
{    
    on_view_customer_click();
    std::string text = "Customer @index? (-1 to return)";
    std::string ans = get_string(text);
    int val = get_int(ans);
    if(val== -1) return;

     int order = store->new_order(val);
     on_view_desktop_click();
      while(true) {
        std::string TEXT = "Desktop (-1 when done)?";
        std::string desktop = get_string(TEXT);
        int val = get_int(desktop);

        if(val == -1) break;
        store->add_desktop(val, order);
    }    
    
      
    on_view_order_click();
     set_msg("Added order " + std::to_string(order) + " for $" + std::to_string(store->order(order).price()));
}
void Mainwin::on_insert_customer_click()
{
    
    std::string name = "Customer Name";
    std::string email = "Customer Email";
    std::string phone="Customer Phone";
    std::string Name = get_string(name);
    std::string Email = get_string(email);
    std::string Phone = get_string(phone);
    Customer customer{Name,Phone,Email};
 
    

    store->add_customer(customer);
    on_view_customer_click();
    set_msg("Added customer " + Name);
    
}
//HELP
void Mainwin::on_about_click()
{
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("ELSA");
    auto logo = Gdk::Pixbuf::create_from_file("store.jpeg");
    dialog.set_logo(logo);
    dialog.set_version("Version 0");
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Hung Nguyen"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by M0tty, licensed under CC BY-SA 3.0 https://commons.wikimedia.org/wiki/File:Pyramidal_matches.svg",
        "Robot by FreePik.com, licensed for personal and commercial purposes with attribution https://www.freepik.com/free-vector/grey-robot-silhouettes_714902.htm"};
    dialog.set_artists(artists);
    dialog.run();
}
std::string Mainwin::get_string(std::string prompt)
{
     EntryDialog edialog{*this, prompt, true};
    edialog.set_secondary_text("What do you want to insert for "+prompt+" today?", true);
    edialog.set_text("Type answer here");
    edialog.run();

  Gtk::MessageDialog mdialog{*this, "Thank you for your response"};
   mdialog.run();
     return edialog.get_text();

}
double Mainwin::get_double(std::string prompt)
{
    double value = std::stod(prompt);
    return value;
}

int Mainwin::get_int(std::string prompt)
{
    int value = std::stoi(prompt);
    return value;
}

Mainwin::~Mainwin() { }
void Mainwin::set_data(std::string s)
{
   data->set_text(s);
}
void Mainwin::set_msg(std::string s)
{
   msg->set_markup(s);
}
void Mainwin::on_new_store_click()
{
    delete store;
    store = new Store{};
}
void Mainwin::on_save_click(){
         try {
             
            std::ofstream ofs{filename};
            store->save(ofs);
            
            if(!ofs) throw std::runtime_error{"Error writing file"};
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to save file: "}.run();
}
}
void Mainwin::on_save_as_click()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
    Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);
    
    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);
    int result = dialog.run();
      
    if (result == 1) {
        try {
            std::ofstream ofs{dialog.get_filename()};
            store->save(ofs);
            
            if(!ofs) throw std::runtime_error{"Error writing file"};
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to save file: "}.run();
        }
    
    }
}
void Mainwin::on_open_click(){
   Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            //delete store;
            std::ifstream ifs{dialog.get_filename()};
            store = new Store{ifs};
            if(!ifs) throw std::runtime_error{"File contents bad"};

        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open elsa"}.run();
        }
    }


      
}

