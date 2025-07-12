import Header from "@/components/screens/home/header";
import Hero from "@/components/screens/home/hero";
import { SafeAreaView } from "react-native-safe-area-context";
import CarBrands from "@/components/screens/home/car-brands";
import TransmissionScreen from "@/components/screens/home/transmission";
import { ScrollView } from "react-native";

const Home = () => {
  return (
    <SafeAreaView style={{ flex: 1 }}>
      <ScrollView
        nestedScrollEnabled={true}
        contentContainerStyle={{
          paddingHorizontal: 24,
          paddingTop: 8,
          gap: 34,
          paddingBottom: 40,
        }}
      >
        <Header />
        <Hero />
        <CarBrands />
        <TransmissionScreen />
      </ScrollView>
    </SafeAreaView>
  );
};

export default Home;
