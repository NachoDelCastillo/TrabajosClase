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

namespace ExamenDSI_1
{
    /// <summary>
    /// Una página vacía que se puede usar de forma independiente o a la que se puede navegar dentro de un objeto Frame.
    /// </summary>
    /// 

    public class dronData
    {
        public Image image;
        public string name;

        public dronData(string _name, BitmapImage imageSource)
        {
            image = new Image();
            image.Source = imageSource;
            name = _name;
        }
    }
        
    public sealed partial class Config : Page
    {
        public ObservableCollection<dronData> ListaDrones { get; } = new ObservableCollection<dronData>();

        public Config()
        {
            this.InitializeComponent();

            ListaDrones.Add(new dronData("uwuw", new BitmapImage(new Uri("ms-appx:///Assets/StoreLogo.png"))));
            ListaDrones.Add(new dronData("uwuw2", new BitmapImage(new Uri("ms-appx:///Assets/Madrid.png"))));
            ListaDrones.Add(new dronData("uwuw3", new BitmapImage(new Uri("ms-appx:///Assets/Barcelona.png"))));
            ListaDrones.Add(new dronData("uwuw4", new BitmapImage(new Uri("ms-appx:///Assets/Bilbao.png"))));
        }

        private void GoBack(object sender, RoutedEventArgs e)
        {
            if (Frame.CanGoBack)
                Frame.GoBack();
        }

        private void OnClick(object sender, RoutedEventArgs e)
        {
            RadioButton ciudadButton = sender as RadioButton;

            string ciudad = ciudadButton.Content.ToString();

            Map.Source = new BitmapImage(new Uri("ms-appx:///Assets/" + ciudad + ".png"));
        }

        private void ListView_ItemClick(object sender, ItemClickEventArgs e)
        {
            dronData data = e.ClickedItem as dronData;
            Foto.Source = data.image.Source;
        }
    }
}
