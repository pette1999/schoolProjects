
import SwiftUI

struct ContentView: View {
    var body: some View {
       MainView()
        
    }
}

struct Home : View {
    
    var animation : Namespace.ID
    @Binding var show : Bool
    @Binding var disShow : Bool
    @Binding var selected : Model
    @Binding var selectedDiscount : DisModel!
    
    var body: some View{

        ScrollView(.vertical, showsIndicators: false) {
            
            VStack{
                
                HStack{
                    VStack{
                        Text("iGrocery")
                        .font(.system(size: 30))
                        .fontWeight(.bold)
                        .foregroundColor(Color("txt"))
                        
                        Text("Discounts")
                            .font(.system(size: 30))
                            .fontWeight(.bold)
                            .foregroundColor(Color("txt"))
                    }
                    
                    
                    
                    Spacer(minLength: 0)
                    
                    Button(action: {}) {
                        
                        Image("search")
                            .renderingMode(.template)
                            .foregroundColor(.white)
                            .padding()
                            .background(Color("Color"))
                            .clipShape(Circle())
                    }
                }
                .padding()
                // since all edges are ignored....
                .padding(.top,UIApplication.shared.windows.first?.safeAreaInsets.top)
                
                ScrollView() {
                    ScrollView(.horizontal) {
                        HStack(spacing: 15){
                            ForEach(disItem){discount in
                                DiscountView(selectedDiscount: discount, animation: animation)
                                    .onTapGesture{
                                        withAnimation(.spring()){
                                            selectedDiscount = discount
                                            disShow.toggle()
                                        }
                                    }
                                
                            }
                        
                            }
                        }
                        .padding()
                    }
                    
                    
                }
                
                HStack{
                    
                    Text("Items")
                        .font(.title)
                        .fontWeight(.bold)
                        .foregroundColor(Color("txt"))
                    
                    Spacer()
                    
                }
                .padding()
                
                ForEach(data){grocery in
                    
                    ZStack(alignment: Alignment(horizontal: .trailing, vertical: .top)) {
                        
                        Image("\(grocery.img)")
                            .resizable()
                            .aspectRatio(contentMode: .fill)
                            .frame(height: 300)
                            .cornerRadius(25)
                            .matchedGeometryEffect(id: grocery.img, in: animation)
                        
                        
                        VStack(alignment: .trailing, spacing: 8) {
                            
                            Text(grocery.title)
                                .font(.title)
                                .fontWeight(.bold)
                                .foregroundColor(.white)
                                .matchedGeometryEffect(id: grocery.title, in: animation)
                            
                            Text(grocery.country)
                                .fontWeight(.bold)
                                .foregroundColor(.white)
                                .matchedGeometryEffect(id: grocery.country, in: animation)
                        }
                        .padding()
                    }
                    .padding()
                    // setting detail Data...
                    .onTapGesture {
                        
                        withAnimation(.spring()){
                            
                            selected = grocery
                            show.toggle()
                        }
                    }
                }
            }
        }
    }



struct Cart : View {
    
    var animation : Namespace.ID
    @Binding var checkShow : Bool
    
    var body: some View{

        CartView(checkShow: checkShow, animation: animation)
    }
}

// Creating Tab Views...

struct MainView : View {
    
    @State var tab = "Home"
    @Namespace var animation
    @State var show = false
    @State var disShow = false
    @State var checkShow = false
    @State var selected : Model = data[0]
    @State var selectedDiscount : DisModel!
    
    var body: some View{
        
        ZStack{
            
            VStack(spacing: 0){
                
                // changing Views Based On tab....
                
                switch(tab){
                
                case "Home": Home(animation: animation, show: $show, disShow: $disShow, selected: $selected, selectedDiscount: $selectedDiscount)
                case "Cart": Cart(animation: animation, checkShow: $checkShow)
                default: Home(animation: animation, show: $show, disShow: $disShow, selected: $selected, selectedDiscount: $selectedDiscount)
                
                }
                
                //Spacer()
            
                
                HStack(spacing: 0){
                    
                    tabButton(title: "Home", tab: $tab)
                    
                    Spacer(minLength: 0)
                    
                    tabButton(title: "Cart", tab: $tab)
                }
                .padding(.top)
                // for smaller size iPhones....
                .padding(.bottom,UIApplication.shared.windows.first!.safeAreaInsets.bottom == 0 ? 5 : UIApplication.shared.windows.first!.safeAreaInsets.bottom)
                .padding(.horizontal,100)
                .background(Color.white)
                .clipShape(RoundedShape(corners: [.topLeft,.topRight]))

            }
            
            // Detail View....
            
            if show{
                
                Detail(selected: $selected, show: $show, animation: animation)
            }
            if selectedDiscount != nil && disShow{
                DisDetailView(selectedDiscount: $selectedDiscount, disShow: $disShow, animation: animation)
            }
        }
        .edgesIgnoringSafeArea(.bottom)
    }
}

// Detail View...

struct Detail : View {
    
    @Binding var selected : Model
    @Binding var show : Bool
    var animation : Namespace.ID
    
    var body: some View{
        
        VStack{
            
            VStack{
                
                ZStack(alignment: Alignment(horizontal: .center, vertical: .top)) {
                    
                    Image(selected.img)
                        .resizable()
                        .aspectRatio(contentMode: .fill)
                        .frame(height: 330)
                        .clipShape(RoundedShape(corners: [.bottomLeft,.bottomRight]))
                        .matchedGeometryEffect(id: selected.img, in: animation)
                    
                    HStack{
                        
                        Button(action: {
                            
                            withAnimation(.spring()){show.toggle()}
                            
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
                
                // Details View...
                
                HStack(alignment: .top){
                    
                    VStack(alignment: .leading, spacing: 12) {
                        
                        Text(selected.title)
                            .font(.title)
                            .foregroundColor(Color("txt"))
                            .fontWeight(.bold)
                            .matchedGeometryEffect(id: selected.title, in: animation)
                        
                    }
                    
                    Spacer(minLength: 0)
                    
                    Text(selected.price)
                        .font(.title)
                        .fontWeight(.bold)
                        .foregroundColor(Color("txt"))
                }
                .padding()
                .padding(.bottom)
            }
            .background(Color.white)
            .clipShape(RoundedShape(corners: [.bottomLeft,.bottomRight]))
            
            // ScrollView For Smaller Size Phones....
            
            if UIScreen.main.bounds.height < 750{
                
                ScrollView(.vertical, showsIndicators: false) {
                    
                    BottomViewBig(selected: $selected)
                }
            }
            else{
                
                BottomViewBig(selected: $selected)
            }
            
            Spacer(minLength: 0)
        }
        .background(Color("bg"))
    }
}

struct BottomView : View {
    
    @State var index = 1
    @Binding var selectedDiscount : DisModel!
    
    var body: some View{
        
        VStack(alignment: .leading, spacing: 15) {
            
            Text("Quantity")
                .font(.title)
                .fontWeight(.bold)
                .foregroundColor(Color("txt"))
                
            HStack(spacing: 15) {
                Button(action: {
                    if selectedDiscount.quantity > 1{selectedDiscount.quantity -= 1}
                }) {
                    
                    Image(systemName: "minus")
                        .font(.system(size: 16, weight: .heavy))
                        .foregroundColor(.black)
                }
                
                Text("\(selectedDiscount.quantity)")
                    .fontWeight(.heavy)
                    .foregroundColor(.black)
                    .padding(.vertical,5)
                    .padding(.horizontal,10)
                    .background(Color.black.opacity(0.06))
                
                Button(action: {selectedDiscount.quantity += 1}) {
                    
                    Image(systemName: "plus")
                        .font(.system(size: 16, weight: .heavy))
                        .foregroundColor(.black)
                }
            }
            
//            Text("Member Of Your Group")
//                .font(.caption)
            
//            HStack(spacing: 15){
//
//
//                ForEach(1...6,id: \.self){i in
//
//                    Button(action: {index = i}) {
//
//                        Text("\(i)")
//                            .fontWeight(.bold)
//                            .foregroundColor(index == i ? .white : .gray)
//                            .padding(.vertical,10)
//                            .padding(.horizontal)
//                            .background(Color("Color").opacity(index == i ? 1 : 0.07))
//                            .cornerRadius(4)
//                    }
//                }
//
//                Spacer(minLength: 0)
//            }
            .padding(.top)
            
            Text("Product Description")
                .font(.title)
                .fontWeight(.bold)
                .foregroundColor(Color("txt"))
                .padding(.top,10)
            
            Text("Organic Better Boy Tomato")
                .multilineTextAlignment(.leading)
            
            Spacer(minLength: 0)
            
            HStack{
                
                Spacer(minLength: 0)
                
                Button(action: {}) {
                    
                    Text("Add to Cart")
                        .fontWeight(.bold)
                        .foregroundColor(.white)
                        .padding(.vertical)
                        .frame(width: UIScreen.main.bounds.width - 100)
                        .background(Color("Color"))
                        .clipShape(Capsule())
                }
                
                Spacer(minLength: 0)
            }
            .padding(.top)
            // since all edges are ignored...
            .padding(.bottom,UIApplication.shared.windows.first?.safeAreaInsets.bottom == 0 ? 15 : UIApplication.shared.windows.first?.safeAreaInsets.bottom)
            
        }
        .padding([.horizontal,.top])
    }
}

struct BottomViewBig : View {
    
    @State var index = 1
    @Binding var selected : Model
    
    var body: some View{
        
        VStack(alignment: .leading, spacing: 15) {
            
            Text("Quantity")
                .font(.title)
                .fontWeight(.bold)
                .foregroundColor(Color("txt"))
            
//            Text("Member Of Your Group")
//                .font(.caption)
            
            HStack(spacing: 15) {
                Button(action: {
                    if selected.quantity > 1{selected.quantity -= 1}
                }) {
                    
                    Image(systemName: "minus")
                        .font(.system(size: 16, weight: .heavy))
                        .foregroundColor(.black)
                }
                
                Text("\(selected.quantity)")
                    .fontWeight(.heavy)
                    .foregroundColor(.black)
                    .padding(.vertical,5)
                    .padding(.horizontal,10)
                    .background(Color.black.opacity(0.06))
                
                Button(action: {selected.quantity += 1}) {
                    
                    Image(systemName: "plus")
                        .font(.system(size: 16, weight: .heavy))
                        .foregroundColor(.black)
                }
            }
            
//            HStack(spacing: 15){
//
//
//                ForEach(1...6,id: \.self){i in
//
//                    Button(action: {index = i}) {
//
//                        Text("\(i)")
//                            .fontWeight(.bold)
//                            .foregroundColor(index == i ? .white : .gray)
//                            .padding(.vertical,10)
//                            .padding(.horizontal)
//                            .background(Color("Color").opacity(index == i ? 1 : 0.07))
//                            .cornerRadius(4)
//                    }
//                }
//
//                Spacer(minLength: 0)
//            }
//            .padding(.top)
            
            Text("Product Description")
                .font(.title)
                .fontWeight(.bold)
                .foregroundColor(Color("txt"))
                .padding(.top,10)
            
            Text("Organic Better Boy Tomato")
                .multilineTextAlignment(.leading)
            
            Spacer(minLength: 0)
            
            HStack{
                
                Spacer(minLength: 0)
                
                Button(action: {}) {
                    
                    Text("Add to Cart")
                        .fontWeight(.bold)
                        .foregroundColor(.white)
                        .padding(.vertical)
                        .frame(width: UIScreen.main.bounds.width - 100)
                        .background(Color("Color"))
                        .clipShape(Capsule())
                }
                
                Spacer(minLength: 0)
            }
            .padding(.top)
            // since all edges are ignored...
            .padding(.bottom,UIApplication.shared.windows.first?.safeAreaInsets.bottom == 0 ? 15 : UIApplication.shared.windows.first?.safeAreaInsets.bottom)
            
        }
        .padding([.horizontal,.top])
    }
}


// Tab Buttons...

struct tabButton : View {
    
    var title : String
    @Binding var tab : String
    
    var body: some View{
        
        Button(action: {tab = title}) {
            
            HStack(spacing: 8){
                
                Image(title)
                    .renderingMode(.template)
                    .foregroundColor(tab == title ? .white : .gray)
                
                
                Text(tab == title ? title : "")
                    .foregroundColor(.white)
                    .fontWeight(.bold)
            }
            .padding(.vertical,10)
            .padding(.horizontal)
            .background(Color("Color").opacity(tab == title ? 1 : 0))
            .clipShape(Capsule())
        }
    }
}

// bottom only corners....

struct RoundedShape : Shape {
    
    // for resuable.....
    var corners : UIRectCorner
    
    func path(in rect: CGRect) -> Path {
        
        let path = UIBezierPath(roundedRect: rect, byRoundingCorners: corners, cornerRadii: CGSize(width: 45, height: 45))
        
        return Path(path.cgPath)
    }
}

// Model And Sample Data...
struct Model : Identifiable {
    
    var id = UUID().uuidString
    var title : String
    var country : String
    var ratings : String
    var price : String
    var img : String
    var quantity: Int
}

var data = [

    Model(title: "Tomato", country: "Produce", ratings: "Fruit", price: "$1.00", img: "tomatoe", quantity: 0),
    Model(title: "Chicken Breast", country: "Meat", ratings: "Poultry", price: "$13.00", img: "chicken", quantity: 0),
   
]
