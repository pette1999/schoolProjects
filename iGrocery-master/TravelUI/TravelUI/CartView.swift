//
//  CartView.swift
//  Cart
//
//  Created by Balaji on 10/10/20.
//

import SwiftUI

struct CartView: View {
    @StateObject var cartData = CartViewModel()
//    @Binding var checkShow : Bool
    @State var checkShow = false
    var animation : Namespace.ID

    var body: some View {
        
        VStack{
            
            HStack(spacing: 20){
                
                Text("My cart")
                    .font(.title)
                    .fontWeight(.heavy)
                    .foregroundColor(.black)
                
                Spacer()
            }
            .padding()
            
            ScrollView(.vertical, showsIndicators: false) {
                
                LazyVStack(spacing: 0){
                    
                    ForEach(cartData.items){item in
                        
                        // ItemView...
                        ItemView(item: $cartData.items[getIndex(item: item)],items: $cartData.items)
                    }
                }
            }
            
            // Bottom View...
            
            VStack{
                
                HStack{
                    
                    Text("Total")
                        .fontWeight(.heavy)
                        .foregroundColor(.gray)
                    
                    Spacer()
                    
                    // calculating Total Price...
                    Text(calculateTotalPrice())
                        .font(.title)
                        .fontWeight(.heavy)
                        .foregroundColor(.black)
                }
                .padding([.top,.horizontal])
                
                
                Button(action: {
                    checkShow = true
                }) {
                    Text("Check out")
                        .font(.title2)
                        .fontWeight(.heavy)
                        .foregroundColor(.white)
                        .padding(.vertical)
                        .frame(width: UIScreen.main.bounds.width - 30)
                        .background(
                            LinearGradient(gradient: .init(colors: [Color("lightblue"),Color("blue")]), startPoint: .leading, endPoint: .trailing)
                        ).sheet(isPresented: $checkShow, content: {
                            CheckOutView(checkShow: $checkShow, animation: animation)
                        })
                        .cornerRadius(15)
                }
                
                
//                if checkShow {
//                    CheckOutView(checkShow: $checkShow, animation: animation)
//                        .onTapGesture{
//                            withAnimation(.spring()){
////                                checkShow.toggle()
//                            }
//                        }
//                }
            }
            .background(Color.white)
            
        }
        .background(Color("gray").ignoresSafeArea())
    }
    
    func getIndex(item: Item)->Int{
        
        return cartData.items.firstIndex { (item1) -> Bool in
            return item.id == item1.id
        } ?? 0
    }
    
    func calculateTotalPrice()->String{
        
        var price : Float = 0
        
        cartData.items.forEach { (item) in
            price += Float(item.quantity) * item.price
        }
        
        return getPrice(value: price)
    }
}
