/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leap;

import com.leapmotion.leap.Controller;
import com.leapmotion.leap.Frame;
import com.leapmotion.leap.Hand;
import com.leapmotion.leap.HandList;
import com.leapmotion.leap.InteractionBox;
import com.leapmotion.leap.Listener;
import com.leapmotion.leap.Pointable;

/**
 *
 * @author thomas
 */
public class listener extends Listener {
    Connect conn= new Connect();

    public void onFrame(Controller controller){
        Frame frame = controller.frame();
        
        Hand firsthand = frame.hands().rightmost();
        if(firsthand.confidence()>.15){
            
            com.leapmotion.leap.Vector velo = firsthand.palmVelocity();
            conn.insert(String.valueOf(velo.get(0)), String.valueOf(velo.get(2)));
            
            conn.selectAll();
            System.out.println("x"+velo.get(0));
            System.out.println("y"+velo.get(1));
            System.out.println("z"+velo.get(2));
            
            
        }
    }


    public void onInit (Controller controller){
        System.out.println("Initialized");
    }

    public void onConnect (Controller controller){
        System.out.println("Connected");
    }

    public void onDisconnect (Controller controller){
        System.out.println("Disconnected");
    }

    public void onFocusGained (Controller controller){
        System.out.println("Focus gained");
    }

    public void  onFocusLost (Controller controller){
        System.out.println("Focus lost");
    }


}
