#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "Store.h"

class Mainwin : public Gtk::Window
 {
    public:
		Mainwin();
		~Mainwin();
    private:
		Store * store;
		Gtk::Label* data;
		Gtk::Label* msg;
		std::string filename;
		std::string _color;
		Gtk::EventBox *eb;
		Gtk::ScrolledWindow *scrolled_window;
    protected:
		void on_disk_click();
		void on_CPU_click();
		void on_new_store_click();
		void on_save_click();
		void on_save_as_click();
		void on_open_click();
		void on_quit_click();
		void on_view_peripheral_click();
		void on_view_desktop_click();
		void on_view_order_click();
		void on_view_customer_click();
		void on_insert_peripheral_click();
		void on_insert_desktop_click();
		void on_insert_order_click();
		void on_insert_customer_click();
		void on_about_click();
		void on_remove_peripheral_click();
		void on_remove_Customer_click();
		void on_find_peripheral_click();
		void on_find_customer_click();
		void on_color_click();
		std::string get_string(std::string prompt);
		double get_double(std::string prompt);
		int get_int(std::string prompt);
		void set_data(std::string s);
		void set_msg(std::string s);
};
#endif 

