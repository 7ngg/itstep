import Header from "@/components/screens/details/header";
import Hero from "@/components/screens/details/hero";
import Info from "@/components/screens/details/info";
import Specifications from "@/components/screens/details/specifications";
import { View, Text } from "react-native";
import { SafeAreaView } from "react-native-safe-area-context";

const Details = () => {
  return (
    <SafeAreaView style={{ flex: 1, backgroundColor: "#0A0F1D", gap: 34 }}>
      <Header />
      <Hero />
      <Info />
      <Specifications />
    </SafeAreaView>
  );
};

export default Details;
