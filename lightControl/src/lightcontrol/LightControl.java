package lightcontrol;

import java.util.logging.Level;
import java.util.logging.Logger;

public class LightControl {

    public static void main(String[] args) {
        Runnable run = () -> {
            Splash loading = new Splash();
            loading.setVisible(true);
            
            try {
                Thread.sleep(5000);
            } catch (InterruptedException ex) {
                Logger.getLogger(LightControl.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            loading.dispose();
            Login login = new Login();
            login.setVisible(true);            
        };
        Thread hiloSplash = new Thread(run);
        hiloSplash.start();/*
        Login login = new Login();
        login.setVisible(true);  */
    }
    
}
