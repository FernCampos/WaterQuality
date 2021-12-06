package phbuoywowawesome.droiduino.phbuoy;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import phbuoywowawesome.R;


public class FirstFragment extends androidx.fragment.app.Fragment {
    public FirstFragment(){}

    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        return inflater.inflate(R.layout.fragment_first, container, false);
    }
}
