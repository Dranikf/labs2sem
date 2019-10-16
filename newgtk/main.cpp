#include <gtk/gtk.h>
#include <libintl.h>

// g++ main.cpp `pkg-config --cflags --libs gtk+-3.0`

// https://www.ibm.com/developerworks/ru/library/os-gtk2/index.html
 
#define _(x) gettext (x)
#define N_(x) (x)
 
#define GETTEXT_PACKAGE "gtk-hello"
#define LOCALEDIR "mo"
 
static char *greetings[] = { "Hello World",
                 "Witaj świecie",
                 "世界に今日は" };
 
static char* choose_greeting ()
{
  return greetings[g_random_int_range (0, G_N_ELEMENTS (greetings))];
}

// обработчик для надатия кнопки
static void cb_button_click(GtkButton *button, gpointer data)
{
  GtkWidget *label = GTK_WIDGET(data);
 
  g_assert(label != NULL);
  gtk_label_set_text(GTK_LABEL (label), choose_greeting());
}

// функция обработчик закрытия окна с программой
static gboolean cb_delete(GtkWidget *window, gpointer data)
{

  // завершает бесконечный цикл gtk
  gtk_main_quit();
  return FALSE;
  // вернув true можно приостановить закрытие окна
}
 
int main (int argc, char *argv[])
{
  // строки программы инициализирующие gtk=====================
  GtkWidget* window, *button, *label, *vbox;// объявление указателей на некоторые виджеты
  
  // функции включающие поддержку интернационаллизации
  bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
  // это наверное включение разных языков для использования в программе
 
  gtk_init(&argc, &argv);// для gtk вызов этой функции обязателен
  // аргументами передаются те параметры с которыми запущена программа
  // строки программы инициализирующие gtk=====================

  // функции создающие новые виджеты++++++++++++++++++++++++
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);// создает новое окно типа TOPLEVEL
  button = gtk_button_new_with_label (_("Hello World"));// создание button
  // _("") это вызов макроса вызывающего подпрограмму gettext являющийся основой 
  //для перевода программы
  label = gtk_label_new (choose_greeting());// создание label
  vbox = gtk_vbox_new(FALSE, 0);// создание вертикального бокса vbox
  // не отображает не одного пикселя, но играет важнейшую роль
  // функции создающие новые виджеты++++++++++++++++++++++++
 
  // определяют расположение виджетов на экране
  gtk_container_add(GTK_CONTAINER (window), vbox);
  // вертикальный контейнер помещаю а окно

  // помещаем лэйбел в вертикальный конгтейнер
  gtk_container_add(GTK_CONTAINER (vbox), label);
  // помещаем кнопку в вертикальный контейнер
  gtk_container_add(GTK_CONTAINER (vbox), button);
 
  // регистрация обратных вызовов++++++++++++++++++++++++++
  // тут регистрирую событие удаления окна
  // т.е. для window событие delete-event вызовет описанную выше cd_delete
  g_signal_connect(G_OBJECT (window), "delete-event", 
           G_CALLBACK(cb_delete), NULL);
 
  // аналогично для clicked  кнопки
  // в последний параметр передается указатель на label

  g_signal_connect (G_OBJECT (button), "clicked", 
            G_CALLBACK (cb_button_click), label);
  // регистрация обратных вызовов++++++++++++++++++++++++++  
 
  // после того как зарегистрировали все эти тонкости
  // отображаем окно
  gtk_widget_show_all(window);

  // запускам главный цикл
  gtk_main();
 
  return 0;
}