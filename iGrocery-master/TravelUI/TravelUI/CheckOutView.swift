//
//  CheckOutView.swift
//  TravelUI
//
//  Created by peter on 5/15/21.
//

import SwiftUI

struct CheckOutView: View {
    
    @Binding var checkShow: Bool
    @State var address = ""
    @State var city = ""
    @State var state = ""
    @State var zip = ""
    @State var cardNumber = ""
    @State var expireDate = ""
    @State var cvc = ""
    @State var coupon = ""
    
    var animation : Namespace.ID
    
    var body: some View{
        
        VStack{
            ScrollView(.vertical, showsIndicators: false) {
                VStack(spacing:15) {
                    ZStack(alignment: Alignment(horizontal: .center, vertical: .top)) {

                        HStack{

                            Button(action: {

                                withAnimation(.spring()){checkShow.toggle()}

                            }) {

                                Image(systemName: "chevron.left")
                                    .foregroundColor(.black)
                                    .padding()
                                    .background(Color.white)
                                    .clipShape(Circle())
                            }

                            Spacer()


                        }
                        .padding()
                        // since all edges are ignored....
                        .padding(.top,UIApplication.shared.windows.first?.safeAreaInsets.top)
                    }
                    
                    HStack(spacing: 20){
                        
                        Text("Coupon")
                            .font(.title)
                            .fontWeight(.heavy)
                            .foregroundColor(Color("txt"))
                        
                        Spacer()
                    }
                    .padding()
                    
                    CardComponent()
                    
                    
                    VStack(spacing:15) {
                        
                        HStack(spacing: 20){
                            
                            Text("Address Info: ")
                                .font(.title)
                                .fontWeight(.heavy)
                                .foregroundColor(Color("txt"))
                            
                            Spacer()
                        }
                        .padding()
                        
                        VStack {
                            CustomTextField(image: "house", title: "Address", value: $address, animation: animation)
                            CustomTextField(image: "house", title: "City", value: $city, animation: animation)
                                .padding(.top,5)
                            
                            CustomTextField(image: "house", title: "State", value: $state, animation: animation)
                                .padding(.top,5)
                            CustomTextField(image: "house", title: "Zip Code", value: $zip, animation: animation)
                                .padding(.top,5)
                        }
                        .foregroundColor(.black)
                        
                        HStack(spacing: 20){
                            
                            Text("Payment Info: ")
                                .font(.title)
                                .fontWeight(.heavy)
                                .foregroundColor(Color("txt"))
                            
                            Spacer()
                        }
                        .padding()
                        
                        VStack {
                            CustomTextField(image: "creditcard", title: "Card Number", value: $cardNumber, animation: animation)
                                .padding(.top,5)
                            CustomTextField(image: "timer", title: "Expiration Date(MM/YYYY)", value: $expireDate, animation: animation)
                                .padding(.top,5)
                            CustomTextField(image: "number", title: "CVC/CVV", value: $cvc, animation: animation)
                                .padding(.top,5)
                            CustomTextField(image: "barcode", title: "Coupn", value: $coupon, animation: animation)
                                .padding(.top,5)
                        }
                        .foregroundColor(.black)
                        
                        Spacer()
                        
                        Button(action: {
                        }) {
                            Text("Confirm")
                                .font(.title2)
                                .fontWeight(.heavy)
                                .foregroundColor(.white)
                                .padding(.vertical)
                                .frame(width: UIScreen.main.bounds.width - 30)
                                .background(
                                    LinearGradient(gradient: .init(colors: [Color("lightblue"),Color("blue")]), startPoint: .leading, endPoint: .trailing)
                                )
                                .cornerRadius(15)
                        }
                        
                    }
                    .padding(.top)
                }

            }
            .padding(.bottom,UIApplication.shared.windows.first!.safeAreaInsets.bottom == 0 ? 5 : UIApplication.shared.windows.first!.safeAreaInsets.bottom)
            .background(Color("gray").ignoresSafeArea())
//            .clipShape(RoundedShape(corners: [.bottomLeft,.bottomRight]))
            
            Spacer(minLength: 0)
        }
        .background(Color("gray").ignoresSafeArea())
    }
}
