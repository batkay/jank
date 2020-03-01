/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leap;
import com.leapmotion.leap.*;
import java.io.IOException;

import java.sql.Connection;
import java.sql.DriverManager;  
import java.sql.SQLException;  
/**
 *
 * @author thomas
 */
public class Leap {

    /**
     * @param args the command line arguments
     */
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        Connect conn= new Connect();
      
       
        Controller controller = new Controller();
        //controller.setPolicyFlags(Controller.PolicyFlag.POLICY_BACKGROUND_FRAMES);
        listener listen = new listener();
        controller.addListener(listen);
        while(controller.isConnected()!= true){         
        }
        
        try{
            System.in.read();
        
        }
        catch(IOException e){
            e.printStackTrace();
        }
        
        controller.removeListener(listen);   
    }
}