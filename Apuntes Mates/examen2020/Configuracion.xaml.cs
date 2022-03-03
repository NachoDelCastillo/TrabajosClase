using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Navigation;

// La plantilla de elemento Página en blanco está documentada en https://go.microsoft.com/fwlink/?LinkId=234238

namespace Examen_4
{
    public class View
    {   
        public Image img;
        public string nombre;
        public View() { }
        public View(string name,BitmapImage x){
            img = new Image();
            nombre = name;
            img.Source = x;
        }
    }
    public sealed partial class Configuracion : Page
    {
        public ObservableCollection<View> ListaView { get; } = new ObservableCollection<View>();

        public Configuracion()
        {
            this.InitializeComponent();
        }

        private void RadioButton_Click(object sender, RoutedEventArgs e)
        {
            var radioButton = sender as RadioButton;
            string radioButtonContent = radioButton?.Content?.ToString();
            if (mapa == null) mapa = new Image();
            switch (radioButtonContent){
                case "Madrid":
                    mapa.Source =  new BitmapImage(new Uri("ms-appx:///Assets/Madrid.png"));
                    break;
                case "Barcelona":
                    mapa.Source = new BitmapImage(new Uri("ms-appx:///Assets/Barcelona.png"));
                    break;
                case "Bilbao":
                    mapa.Source = new BitmapImage(new Uri("ms-appx:///Assets/Bilbao.png"));
                    break;
                default:
                    break;
            }
        }

        private void GridView_ItemClick(object sender, ItemClickEventArgs e)
        {
            View x = e?.ClickedItem as View;
            if (nombre == null) nombre = new Image();
            nombre.Source = x.img.Source;
            perfil.Text = "Hola soy "+x.nombre;
        }
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            ListaView.Add(new View("LUIS 1", new BitmapImage(new Uri("ms-appx:///Assets/luis.png"))));
            ListaView.Add(new View("LUIS 2", new BitmapImage(new Uri("ms-appx:///Assets/luis.png"))));
            ListaView.Add(new View("LUIS 3", new BitmapImage(new Uri("ms-appx:///Assets/luis.png"))));
            ListaView.Add(new View("LUIS 4", new BitmapImage(new Uri("ms-appx:///Assets/luis.png"))));
            ListaView.Add(new View("LUIS 5", new BitmapImage(new Uri("ms-appx:///Assets/luis.png")))); 
            ListaView.Add(new View("LUIS 6", new BitmapImage(new Uri("ms-appx:///Assets/luis.png"))));
            ListaView.Add(new View("LUIS 7", new BitmapImage(new Uri("ms-appx:///Assets/luis.png"))));
            ListaView.Add(new View("LUIS 8", new BitmapImage(new Uri("ms-appx:///Assets/luis.png"))));
            ListaView.Add(new View("LUIS 9", new BitmapImage(new Uri("ms-appx:///Assets/luis.png"))));           
            base.OnNavigatedTo(e);
        }
    }
}
