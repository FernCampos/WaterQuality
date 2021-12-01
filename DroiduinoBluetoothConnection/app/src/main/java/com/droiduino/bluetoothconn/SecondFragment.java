package com.droiduino.bluetoothconn;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

public class SecondFragment extends androidx.fragment.app.Fragment {
    public SecondFragment(){}

    TextView readingValue;

    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        View view = inflater.inflate(R.layout.fragment_second, container, false);
        readingValue = (TextView)view.findViewById(R.id.textView2);
        return view;
        //return inflater.inflate(R.layout.fragment_second, container, false);
    }
}
