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

    Gtk::MenuItem *menuitem_CPU = Gtk::manage(new Gtk::MenuItem("_BONUS CPU DATA", true));
    menuitem_CPU->signal_activate().connect([this] {this->on_CPU_click();});
    helpmenu->append(*menuitem_CPU);

    Gtk::MenuItem *menuitem_disk = Gtk::manage(new Gtk::MenuItem("_BONUS DISK DATA", true));
    menuitem_disk->signal_activate().connect([this] {this->on_disk_click();});
    helpmenu->append(*menuitem_disk);
  
    data = Gtk::manage(new Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START});
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);
    set_data("WELCOME TO MY STORE FOR SPRINT 3\n\nHow can i help you today?");

    

     msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
  Gtk::EventBox *eb = Gtk::manage(new Gtk::EventBox);
    data->set_hexpand();
    data->override_background_color(Gdk::RGBA("yellow"));
    vbox->add(*data);
    vbox->show_all();
}
//VIEW
void Mainwin::on_disk_click()
{   Options o{"CLOUD 10TB", 2423.47};                      store->add_option(o);
    o = Options{"0.5 TB SSD", 79.99};                      store->add_option(o);
    o = Options{"1 TB SSD", 109.99};                       store->add_option(o);
    o = Options{"2 TB SSD", 229.99};                       store->add_option(o);
    o = Options{"4 TB SSD", 599.99};                       store->add_option(o);

    o = Options{"1 TB PC Disk", 44.83};                    store->add_option(o);
    o = Options{"2 TB Hybrid Disk", 59.99};                store->add_option(o);
    o = Options{"4 TB Hybrid Disk", 93.98};                store->add_option(o);
}
void Mainwin::on_CPU_click()
{
    Options o{"CPU: 2.6 GHz Xeon 6126T", 2423.47};         store->add_option(o);
    o = Options{"CPU: 2.4 GHz Core i7-8565U", 388.0};      store->add_option(o);
    o = Options{"CPU: 2.2 GHz AMD Opteron", 37.71};        store->add_option(o);
    o = Options{"CPU: 300 MHz AM3351BZCEA30R ARM", 11.03}; store->add_option(o);
    o = Options{"CPU: 240 MHz ColdFire MCF5", 17.33};      store->add_option(o);

    o = Options{"2 GB RAM", 17.76};                        store->add_option(o);
    o = Options{"4 GB RAM", 22.95};                        store->add_option(o);
    o = Options{"8 GB RAM", 34.99};                        store->add_option(o);
    o = Options{"16 GB RAM", 92.99};                       store->add_option(o);
    o = Options{"32 GB RAM", 134.96};                      store->add_option(o);
    o = Options{"64 GB RAM", 319.99};                      store->add_option(o);
    o = Options{"0.5 TB SSD", 79.99};                      store->add_option(o);
    o = Options{"1 TB SSD", 109.99};                       store->add_option(o);
    o = Options{"2 TB SSD", 229.99};                       store->add_option(o);
    o = Options{"4 TB SSD", 599.99};                       store->add_option(o);

    o = Options{"1 TB PC Disk", 44.83};                    store->add_option(o);
    o = Options{"2 TB Hybrid Disk", 59.99};                store->add_option(o);
    o = Options{"4 TB Hybrid Disk", 93.98};                store->add_option(o);

}
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
    {
     oss<< i << ") " << store->order(i) << "\n";
     oss<< "Total Price: $"<<store->order(i).price()<<"\n\n";
    }
     set_data(oss.str());
}
void Mainwin::on_quit_click()
{
	close();
}
///INSERT
void Mainwin::on_insert_peripheral_click()
{
    Gtk::Dialog dialog{"INSERT PERIPHERAL RATT TA TA", *this};
    Gtk::Grid grid;
    Gtk::Label l_pname{"Product Name"};
    Gtk::Entry e_pname;               // Accept any line of text

    grid.attach(l_pname, 0, 1, 1, 1);
    grid.attach(e_pname, 1, 1, 2, 1);

    Gtk::Label l_pcost{"Product Cost"};
    Gtk::Entry e_pcost;               // Accept any line of text

    grid.attach(l_pcost, 0, 2, 1, 1);
    grid.attach(e_pcost, 1, 2, 2, 1);

    // Now add the grid to the dialog's VBox (called its "content area")
    dialog.get_content_area()->add(grid);

 
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

    int response;
    dialog.show_all();
    while((response = dialog.run()) != Gtk::RESPONSE_CANCEL) {

 
     if (e_pname.get_text().size() == 0) {e_pname.set_text("*required*"); continue;}
    else if (e_pcost.get_text().size() == 0) {e_pcost.set_text("*required*"); continue;}
        
    std::string name = e_pname.get_text();
    std::string num  = e_pcost.get_text();

    double cost = get_double(num);
    Options option{name,cost};
    store->add_option(option);
  
    on_view_peripheral_click(); 
    }
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
                Gtk::MessageDialog{*this, "#### INVALID OPTION ####\n\n"}.run();
                
             }
    }
    on_view_desktop_click();
    set_msg("Added desktop " + std::to_string(desktop));
}
void Mainwin::on_insert_order_click()
{    

       on_view_customer_click(); // SHOW THE CONTENT OF CUSTOMER

     Gtk::Dialog dialog{"INSERT ORDER", *this};
    Gtk::Grid grid;
    Gtk::Label l_cnum{"Customer @index"};
    Gtk::Entry e_cnum;               // Accept any line of text

    grid.attach(l_cnum, 0, 1, 1, 1);
    grid.attach(e_cnum, 1, 1, 2, 1);

    Gtk::Label l_dnum{"Desktop @index"};
    Gtk::Entry e_dnum;               // Accept any line of text

    grid.attach(l_dnum, 0, 2, 1, 1);
    grid.attach(e_dnum, 1, 2, 2, 1);

    // Now add the grid to the dialog's VBox (called its "content area")
    dialog.get_content_area()->add(grid);

 
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

    int response;
    dialog.show_all();
    while((response = dialog.run()) != Gtk::RESPONSE_CANCEL) {
    if((response = dialog.run()) == Gtk::RESPONSE_OK){on_view_order_click();}
      
     if (e_cnum.get_text().size() == 0) {e_cnum.set_text("*required*"); continue;}
    else if (e_dnum.get_text().size() == 0) {e_dnum.set_text("*required*"); on_view_desktop_click(); continue;}
        
    std::string c_num = e_cnum.get_text();
    on_view_desktop_click(); // SHOW THE CONTENT OF DESKTOP
    std::string d_num  = e_dnum.get_text();

    int cus_num = get_int(c_num);
    int des_num = get_int(d_num);
    if(cus_num || des_num == -1){break;};
    int order;
     order = store->new_order(cus_num);
    store->add_desktop(cus_num,order);
    
    }




}
void Mainwin::on_insert_customer_click()
{
    Gtk::Dialog dialog{"CUSTOMER INFO", *this};
    
        Gtk::Grid grid;

    // Add the animal type


    // Accept the animal's name
    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;               // Accept any line of text

    grid.attach(l_name, 0, 1, 1, 1);
    grid.attach(e_name, 1, 1, 2, 1);

    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;               // Accept any line of text

    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

    Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;               // Accept any line of text

   grid.attach(l_phone, 0, 3, 1, 1);
    grid.attach(e_phone, 1, 3, 2, 1);




    // Now add the grid to the dialog's VBox (called its "content area")
    dialog.get_content_area()->add(grid);

    // Add 2 buttons (Gtk::Dialog handles buttons for you, just use add_button method!)
    // Button response IDs are from https://developer.gnome.org/gtkmm/stable/group__gtkmmEnums.html
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    // NOTE: The x in the title bar to close the dialog is Gtk::RESPONSE_DELETE_EVENT
    int response;

    // It's ready!  Now display it to the user.
    dialog.show_all();
     while((response = dialog.run()) != Gtk::RESPONSE_CANCEL) {

        // Data validation: If the user doesn't enter a name for the animal, complain
       
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        else if (e_email.get_text().size() == 0) {e_email.set_text("*required*"); continue;}
        else if (e_phone.get_text().size() == 0) {e_phone.set_text("*required*"); continue;}
        else 
         {std::string Name = e_name.get_text();
        std::string Email = e_email.get_text();
        std::string Phone = e_phone.get_text();
        Customer customer{Name,Phone,Email};
        store->add_customer(customer); 
   
        on_view_customer_click();
         }
    
     }

    
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
double Mainwin::get_double(std::string prompt) {
    try {
        return std::stod(prompt);
    } catch(std::exception& e) {
        
        return -1.0;
    }
}
int Mainwin::get_int(std::string prompt) {
    try {
        return std::stoi(prompt);
    } catch(std::exception& e) {
        
        return -1;
    }
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
            filename = dialog.get_filename();
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
            filename = dialog.get_filename();
            std::ifstream ifs{dialog.get_filename()};
            store = new Store{ifs};
            if(!ifs) throw std::runtime_error{"File contents bad"};

        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open elsa"}.run();
        }
    }


      
}
